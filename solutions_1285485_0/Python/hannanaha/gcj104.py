import itertools

OEXT = ".out"
CASE_PRFX = "Case #%s: "


def get_quadtant(loc):
    x = loc[0]
    y = loc[1]
    if x > 0 and y >= 0:
        return "UR"
    if x <= 0 and y > 0:
        return "UL"
    if x < 0 and y <= 0:
        return "DL"
    return "DR"

    
def mirror(hl, hr, D):
    # make rights
    next_right = hl
    right = [2*hr]
    if right[-1] <= D:
        while True:
            if next_right == hl:
                right.append(right[-1]+2*hl)
                next_right = hr
            else:
                right.append(right[-1]+2*hr)
                next_right = hl
            if right[-1] > D:
                right = right[:-1]
                break
            
    # make lefts
    next_left = hr
    left = [-2*hl]
    if abs(left[-1]) <= D:
        while True:
            if next_left == hr:
                tmp = [left[0] - 2*hr]
                tmp.extend(left)
                left = tmp
                next_left = hl
            else:
                tmp = [left[0] - 2*hl]
                tmp.extend(left)
                left = tmp
                next_left = hr
            if abs(left[0]) > D:
                left = left[1:]
                break
            
    left.append(0)
    left.extend(right)
    return left



# SMALL ONLY!
def read_input(filename):
    data = []
    with open(filename, "r") as f:
        cases = int(f.readline())
        for _ in xrange(cases):
            case = f.readline().strip().split()
            h = int(case[0])
            w = int(case[1])
            d = float(case[2])
            for row in xrange(h):
                newrow = f.readline()
                if "X" in newrow:
                    yc = row
                    xc = newrow.index("X")
                    vert = {"vd": h - 1 - yc - 0.5, "vu": yc - 1 + 0.5}
                    horiz = {"hl": xc - 1 + 0.5, "hr": w - 1 - xc - 0.5}
            data.append((h, w, d, vert, horiz))
    print data
    return data

def make_output(fname, output):
    fname = fname + OEXT
    with open(fname, "w") as f:
        restext = []
        for i, v in enumerate(output):
            restext.append(CASE_PRFX % (i+1,) + str(v) + "\n")
        f.writelines(restext)
    
def main(fname):
    data = read_input(fname)
    output = []
    for case in data:
        horiz = mirror(case[4]["hl"], case[4]["hr"], case[2])
        vert = mirror(case[3]["vd"], case[3]["vu"], case[2])
        locs = itertools.product(horiz, vert)
        in_range_images = []
        angles = []
        DD = case[2] ** 2
        for loc in locs:
            r = loc[0]**2 + loc[1]**2 
            if r > 0 and r <= DD:
                in_range_images.append(loc)
                try:
                    angles.append((get_quadtant(loc), loc[1]/loc[0]))
                except ZeroDivisionError:
                    angles.append((get_quadtant(loc), None))
        print angles
        output.append(len(set(angles)))
    make_output(fname, output)




main("examples.in")
main("small.in")

