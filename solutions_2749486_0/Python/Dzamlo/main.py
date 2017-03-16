#! /usr/bin/env python

def check_paths(paths, goal):
    return paths.get(goal)
          

def find_path(X,Y):
    goal = (X,Y)
    paths = {(0,0): ''}
    correct_path = None
    i = 1
    while correct_path is None:
        new_paths = dict()
        for XY,path in paths.iteritems():
           new_paths[(XY[0], XY[1]+i)] = path+'N'
           new_paths[(XY[0], XY[1]-i)] = path+'S'
           new_paths[(XY[0]+i, XY[1])] = path+'E'
           new_paths[(XY[0]-i, XY[1])] = path+'W'
        paths = new_paths
        correct_path = check_paths(paths, goal)
        i += 1
    return correct_path
t = input()
for i in xrange(1, t+1):
    X, Y = raw_input().split()
    X = int(X)
    Y = int(Y)
    print 'Case #%d: %s' % (i, find_path(X,Y))

