#! /usr/bin/env python
#coding=utf-8

#import matplotlib.pyplot as plt
import math

class Mirror(object):
    def __init__(self, type, pos, dir, range=None):
        self.type = type
        self.pos = pos
        self.dir = dir
        self.range = range
        
    def getImg(self, pnt):
        if self.type == 'h':
            d = pnt[1] - self.pos
            if d * self.dir > 0:
                return (pnt[0], self.pos - d)
            else:
                return None
        else:
            d = pnt[0] - self.pos
            if d * self.dir > 0:
                return (self.pos - d, pnt[1])
            else:
                return None
        
    def getId(self):
        return (self.type, self.pos, self.dir)
    
def gen_mrs(map, w, h):
    mrs = {}
    for ix in xrange(w):
        for iy in xrange(h):
            if map[iy][ix] == '#':
                if ix - 1 >= 0 and map[iy][ix-1] != '#':
                    m = Mirror('v', ix, -1)
                    if m.getId() not in mrs:
                        mrs[m.getId()] = m
                if ix + 1 < w and map[iy][ix+1] != '#':
                    m = Mirror('v', ix+1, 1)
                    if m.getId() not in mrs:
                        mrs[m.getId()] = m
                if iy - 1 >= 0 and map[iy-1][ix] != '#':
                    m = Mirror('h', iy, -1)
                    if m.getId() not in mrs:
                        mrs[m.getId()] = m
                if iy + 1 < h and map[iy+1][ix] != '#':
                    m = Mirror('h', iy+1, 1)
                    if m.getId() not in mrs:
                        mrs[m.getId()] = m
    return mrs
                
def collectImgs(orig, pnt, imgs, mrs, dis, _pnts):
    dx = pnt[0] - orig[0]
    dy = pnt[1] - orig[1]
    if (dx, dy) in _pnts:
        return
    
    if dx != 0 or dy != 0:
        len = (dx*dx+dy*dy)**0.5
        if len > dis:
            return
        
        ray = (dx/len, dy/len)
        _pnts.add((dx, dy))
        rad = math.atan2(dy, dx)
        if rad not in imgs:
            imgs.add(rad)
#            print ray
    
    for k, m in mrs.items():
#        print m.getId(), pnt,
        p = m.getImg(pnt)
        if p:
#            print p
            collectImgs(orig, p, imgs, mrs, dis, _pnts)
#            pnts.append(p)
        else:
#            print None
            pass
    pass

def solve(icase, case_input):
    case_output = 'Case #%i: '%icase
    
    ns = case_input[0]
    rn, cn, dis = [int(x) for x in ns.split()]
    map = case_input[1:]
    mrs = gen_mrs(map, cn, rn)
    
    for oy in xrange(rn):
        for ox in xrange(cn):
            if map[oy][ox] == 'X':
                orig = (ox+0.5, oy+0.5)
                
    imgs = set()
    imglist = [orig,]
    imgpnts = set()
    collectImgs(orig, orig, imgs, mrs, dis, imgpnts)
    result = len(imgs)
#    print imgs

#    for p in imgpnts:
#        xx = [0, p[0]]
#        yy = [0, p[1]]
#        plt.plot(xx, yy, 'o-')
#    plt.show()

    case_output += '%d'%result
    
    return case_output


def main():
    global use_test_data
    global test_data
    global input_file
    global output_file
    
    if use_test_data:
        data = [x.strip() for x in test_data.split('\n')]
    else:
        data = [x.strip() for x in input_file.readlines()]
    
    T = int(data[0])
    iLine = 1
    caseLineNum = 1
    for icase in range(1, T + 1):
        input = []
        caseLineNum = 1 + int(data[iLine].split()[0])
        for i in range(caseLineNum):
            input.append(data[iLine])
            iLine += 1
        rslt = solve(icase, input)
        print rslt
        if not use_test_data:
            print >> output_file, rslt
    
    if not use_test_data:
        input_file.close()
        output_file.close()
    
    
if __name__ == '__main__':
    test_data = """6
3 3 1
###
#X#
###
3 3 2
###
#X#
###
4 3 8
###
#X#
#.#
###
7 7 4
#######
#.....#
#.....#
#..X..#
#....##
#.....#
#######
5 6 3
######
#..X.#
#.#..#
#...##
######
5 6 10
######
#..X.#
#.#..#
#...##
######
"""
    use_test_data = False
    
    test_file = 'D-small-attempt0.in'
    if not use_test_data and '' != test_file:
        input_file = open(test_file)
        output_file = open(test_file + '.out', 'w')
    
    main()