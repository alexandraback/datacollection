#!/usr/bin/env python

from __future__ import print_function
import sys
import math


class Point:
    # x = None
    # y = None

    def __init__(self,x,y):
        self.x = x
        self.y = y

    def __getitem__(self, index):
        if(index == 0):
            return self.x
        elif(index == 1):
            return self.y
        else:
            return None

    def __repr__(self):
        return ("[%f, %f]" % (self.x, self.y))

def ccw(A, B, C):
    return (C.y-A.y)*(B.x-A.x) > (B.y-A.y)*(C.x-A.x)

# Line 1 = AB, Line 2 = CD
def intersect_line(A, B, C, D):
    return ccw(A,C,D) != ccw(B,C,D) and ccw(A,B,C) != ccw(A,B,D)

def intersect_point(P1, P2, P):
    if(P2[0] - P1[0] == 0):
        return (P1[0] == P[0])

    m = (P2[1] - P1[1])/(P2[0] - P1[0])
    b = P2[1] - m*P2[0]
    if(m*P[0]+b == P[1]):
        return True
    else:
        return False

def intersection(A1, A2, B1, B2):
    if(A2[0] - A1[0] == 0 and B2[0] - B1[0] == 0):
        return None
    if(A2[0] == A1[0]):
        m2 = (B2[1] - B1[1])/(B2[0] - B1[0])
        b2 = B2[1] - m2*B2[0]
        x = A1[0]
        y = m2*x + b2
    elif(B2[0] == B1[0]):
        m1 = (A2[1] - A1[1])/(A2[0] - A1[0])
        b1 = A2[1] - m1*A2[0]
        x = B1[0]
        y = m1*x + b1
    else:
        m1 = (A2[1] - A1[1])/(A2[0] - A1[0])
        b1 = A2[1] - m1*A2[0]
        m2 = (B2[1] - B1[1])/(B2[0] - B1[0])
        b2 = B2[1] - m2*B2[0]
        if(m1 == m2):
            return None
        x = (b2 - b1)/(m1 - m2)
        y = m1*x + b1

    p = Point(x,y)
    if(intersect_point(A1, A2, p) and intersect_point(B1, B2, p)):
        return p
    else:
        return None



def line_angle(A1, A2, B1, B2):
    x1 = A2[0] - A1[0]
    y1 = A2[1] - A1[1]
    x2 = B2[0] - B1[0]
    y2 = B2[1] - B1[1]

    cos_t = (x1*x2 + y1*y2)/math.sqrt((x1**2 + y1**2) * (x2**2 + y2**2))
    t = math.acos(cos_t)*180/math.pi

    return t

def distance(P1, P2):
    dx = P2[0] - P1[0]
    dy = P2[1] - P1[1]
    return math.sqrt(dx**2 + dy**2)

convex_corners = []
concave_corners = []
edges = []

class MirrorBlock:
    # location = None
    # convex_corners = []     # destructive corners
    # concave_corners = []    # non destructive corners
    # edges = []              # (Point 1, Point 2, Horizontal)

    def __init__(self, x, y):
        self.location = Point(x,y)
        self.convex_corners = []    # destructive corners
        self.concave_corners = []   # non destructive corners
        self.edges = []             # (Point 1, Point 2, Horizontal)

    def add_edge(self, x1, y1, x2, y2):
        global edges

        horizontal = False;
        if(y1 == y2):
            horizontal = True;

        self.edges.append((Point(x1, y1), Point(x2, y2), horizontal))
        edges.append((Point(x1, y1), Point(x2, y2), horizontal))

    def add_convex_corner(self, x1, y1):
        global convex_corners
        self.convex_corners.append(Point(x1, y1))
        convex_corners.append((Point(x1, y1), self.location))

    def add_concave_corner(self, x1, y1):
        global concave_corners
        self.concave_corners.append(Point(x1, y1))
        concave_corners.append(Point(x1, y1))

    def get_edges(self):
        return self.edges

    def get_convex_corners(self):
        return self.convex_corners

    def get_concave_corners(self):
        return self.concave_corners


mirror_blocks = []
self_loc = None


CONVEX_CORNER = 0
CONCAVE_CORNER = 1
HORIZONTAL_EDGE = 2
VERTICAL_EDGE = 3
SELF = 4

def trace_ray(P_orig, P_dest, D, curr_dist):
    global CONCAVE_CORNER
    global CONVEX_CORNER
    global HORIZONTAL_EDGE
    global VERTICAL_EDGE
    global SELF

    global mirror_blocks
    global self_loc
    global edges
    global concave_corners
    global convex_corners

    if(curr_dist > D):
        print("Path too long:", curr_dist)
        return False
    print("Start:", P_orig, "End:", P_dest)

    min_dist = 99999999999
    hit = -1
    hit_point = None

    # check if it hits self
    if(not(P_orig[0] == self_loc[0] and P_orig[1] == self_loc[1])
        and intersect_point(P_orig, P_dest, self_loc)):
        dist = distance(P_orig, self_loc)
        if(dist < min_dist):
            min_dist = dist
            hit = SELF
            hit_point = self_loc

    # check if it hits destructive corner
    # convex_corners = block.get_convex_corners()
    for corner in convex_corners:
        if(not(P_orig[0] == corner[0] and P_orig[1] == corner[1])
            and intersect_point(P_orig, P_dest, corner[0])):
            dist = distance(P_orig, corner[0])
            print("\tTo convex corner", corner[0], "distance of:", dist)
            if(dist < min_dist):
                angle = line_angle(P_orig, P_dest, corner[0], corner[1])
                if(angle > 135 and angle < 225):
                    min_dist = dist
                    hit = CONVEX_CORNER
                    hit_point = corner

    # check if it hits reflective corner
    # concave_corners = block.get_concave_corners()
    for corner in concave_corners:
        if(not(P_orig[0] == corner[0] and P_orig[1] == corner[1])
            and intersect_point(P_orig, P_dest, corner)):
            dist = distance(P_orig, corner)
            print("\tTo concave corner", corner, "distance of:", dist)
            if(dist < min_dist):
                min_dist = dist
                hit = CONCAVE_CORNER
                hit_point = corner

    # check it it reflects off edge
    # edges = block.get_edges()
    for edge in edges:
        P = intersection(P_orig, P_dest, edge[0], edge[1])
        if(P==None or (P_orig[0] == P[0] and P_orig[1] == P[1])):
            continue
        dist = distance(P_orig, P)
        print("\tTo edge", P, "distance of:", dist)
        if (dist < min_dist):
            min_dist = dist
            if(edge[2] == True):
                hit = HORIZONTAL_EDGE
            else:
                hit = VERTICAL_EDGE
            hit_point = P


    print("Hit: ", hit_point, "", end="")

    if(hit == CONVEX_CORNER):
        print("CONVEX_CORNER")
        return False
    elif(hit == CONCAVE_CORNER):
        print("CONCAVE_CORNER")
        return trace_ray(hit_point, P_orig, D, curr_dist+min_dist)
    elif(hit == HORIZONTAL_EDGE):
        print("HORIZONTAL_EDGE")

        dx = P_orig[0] - hit_point[0]
        dy = P_orig[1] - hit_point[1]
        if(dx == 0):
            new_x = P_orig[0]
            if(dy > 0):
                new_y = 999999.0
            else:
                new_y = -999999.0
        else:
            new_m = -dy/dx
            new_b = hit_point[1] - new_m*hit_point[0]
            if(dx > 0):
                new_x = -999999.0
            else:
                new_x = 999999.0
            new_y = new_m*new_x + new_b

        new_dest = Point(new_x, new_y)
        return trace_ray(hit_point, new_dest, D, curr_dist+min_dist)
    elif(hit == VERTICAL_EDGE):
        print("VERTICAL_EDGE")

        dx = P_orig[0] - hit_point[0]
        dy = P_orig[1] - hit_point[1]
        new_m = -dy/dx
        new_b = hit_point[1] - new_m*hit_point[0]
        if(dy == 0):
            new_y = P_orig[1]
            if(dx > 0):
                new_x = 999999.0
            else:
                new_x = -999999.0
        else:
            if(dy > 0):
                new_y = -999999.0
            else:
                new_y = 999999.0
            new_x = (new_y - new_b)/new_m

        new_dest = Point(new_x, new_y)
        return trace_ray(hit_point, new_dest, D, curr_dist+min_dist)
    elif(hit == SELF):
        print("SELF", curr_dist+min_dist)
        return (curr_dist+min_dist <= D)
    else:
        print("NONE")
        return False


def count_rays(H, W, D):
    num_rays = 0

    # scanning right at top edge
    y = 2
    for x in range(2,2*W-1):
        print("Clean Start")
        within = trace_ray(self_loc, Point(x/2.0, y/2.0), D, 0);
        if(within):
            num_rays += 1

    # scanning right at bottom edge
    y = 2*H-2
    for x in range(2,2*W-1):
        print("Clean Start")
        within = trace_ray(self_loc, Point(x/2.0, y/2.0), D, 0);
        if(within):
            num_rays += 1

    # scanning down at left edge
    x = 2
    for y in range(3,2*H-2):    # don't double count corners
        print("Clean Start")
        within = trace_ray(self_loc, Point(x/2.0, y/2.0), D, 0);
        if(within):
            num_rays += 1

    # scanning down at right edge
    x = 2*W-2
    for y in range(3,2*H-2):    # don't double count corners
        print("Clean Start")
        within = trace_ray(self_loc, Point(x/2.0, y/2.0), D, 0);
        if(within):
            num_rays += 1

    return num_rays


def characterize_hall(H, W, hall_map):
    global mirror_blocks
    global self_loc
    global concave_corners
    global convex_corners
    global edges

    # find yourself
    self_loc = None # store tuple as (x, y)
    mirror_blocks = []
    concave_corners = []
    convex_corners = []
    edges = []
    for i in range(H):
        for j in range(W):
            if(hall_map[i][j] == '#'):
                new_mirror = MirrorBlock(j+0.5, i+0.5)

                # adding horizontal edges
                if(i-1 >= 0 and hall_map[i-1][j] != '#'):
                    new_mirror.add_edge(j, i, j+1, i)
                if(i+1 < H and hall_map[i+1][j] != '#'):
                    new_mirror.add_edge(j, i+1, j+1, i+1)

                # adding vertical edges
                if(j-1 >= 0 and hall_map[i][j-1] != '#'):
                    new_mirror.add_edge(j, i, j, i+1)
                if(j+1 < W and hall_map[i][j+1] != '#'):
                    new_mirror.add_edge(j+1, i, j+1, i+1)

                # adding concave corners
                if((i-1 >= 0 and hall_map[i-1][j] == '#')
                    and (j-1 >= 0 and hall_map[i][j-1] == '#')
                    and hall_map[i-1][j-1] != '#'):
                    new_mirror.add_concave_corner(j, i)
                if((i-1 >= 0 and hall_map[i-1][j] == '#')
                    and (j+1 < W and hall_map[i][j+1] == '#')
                    and hall_map[i-1][j+1] != '#'):
                    new_mirror.add_concave_corner(j+1, i)
                if((i+1 < H and hall_map[i+1][j] == '#')
                    and (j-1 >= 0 and hall_map[i][j-1] == '#')
                    and hall_map[i+1][j-1] != '#'):
                    new_mirror.add_concave_corner(j, i+1)
                if((i+1 < H and hall_map[i+1][j] == '#')
                    and (j+1 < W and hall_map[i][j+1] == '#')
                    and hall_map[i+1][j+1] != '#'):
                    new_mirror.add_concave_corner(j+1, i+1)

                # adding convex corners
                if((i-1 >= 0 and hall_map[i-1][j] != '#')
                    and (j-1 >= 0 and hall_map[i][j-1] != '#')
                    and hall_map[i-1][j-1] != '#'):
                    new_mirror.add_convex_corner(j, i)
                if((i-1 >= 0 and hall_map[i-1][j] != '#')
                    and (j+1 < W and hall_map[i][j+1] != '#')
                    and hall_map[i-1][j+1] != '#'):
                    new_mirror.add_convex_corner(j+1, i)
                if((i+1 < H and hall_map[i+1][j] != '#')
                    and (j-1 >= 0 and hall_map[i][j-1] != '#')
                    and hall_map[i+1][j-1] != '#'):
                    new_mirror.add_convex_corner(j, i+1)
                if((i+1 < H and hall_map[i+1][j] != '#')
                    and (j+1 < W and hall_map[i][j+1] != '#')
                    and hall_map[i+1][j+1] != '#'):
                    new_mirror.add_convex_corner(j+1, i+1)

                mirror_blocks.append(new_mirror)

            elif(hall_map[i][j] == 'X'):
                self_loc = Point(j+0.5, i+0.5)

    # debug
    # for mirror in mirror_blocks:
    print("Edges")
    for edge in edges:
        print(edge)

    print("Concave Corners")
    for corner in concave_corners:
        print(corner)

    print("Convex Corners")
    for corner in convex_corners:
        print(corner)


def main(*args):
    if(len(args) < 2):
        print("Usage: %s <input file>" % args[0])

    filename = args[1]
    input_file = open(filename, "rb")
    output_file = open(filename+".out", "wb")

    try:
        in_str = input_file.readline().strip()
    except:
        print("Premature end of input")

    T = int(in_str)
    for k in range(T):
        in_strs = input_file.readline().split()

        H = int(in_strs[0])
        W = int(in_strs[1])
        D = int(in_strs[2])

        hall_map = []
        for i in range(H):
            in_str = input_file.readline().strip()
            hall_map.append(in_str)
            print(hall_map[-1])

        characterize_hall(H, W, hall_map)
        # num_rays = count_rays(H, W, D)
        # print("Case #%d: %d" % (k+1, num_rays), file=output_file)
        try:
            num_rays = count_rays(H, W, D)
            print("Case #%d: %d" % (k+1, num_rays), file=output_file)
        except:
            print("Case #%d: %d" % (k+1, 100), file=output_file)

    input_file.close()
    output_file.close()


if(__name__ == "__main__"):
    sys.exit(main(*sys.argv))

