'''
Created on 2012/04/28

@author: hanaue51
'''
import os
os.chdir("../../../data/2012/round1a/")
filename = "B-small-attempt0"
postfix_in = ".in"
postfix_out = ".out"
format = "Case #%d: %s\n"

infile = open(os.getcwd() + "/" + filename + postfix_in, "r")
lines = infile.readlines()
infile.close()

n_cases = int(lines[0].strip())
results = []
index = 1
for i in xrange(n_cases):
    n_levels = int(lines[index].strip())
    index += 1
    levels = []
    for j in xrange(n_levels):
        elems = lines[index].strip().split()
        index += 1
        levels.append([int(elems[0]), int(elems[1]), 0])
    answer = 0
    
#    levels.sort()
    current_stars = 0
    n_steps = 0
#    print levels
    while True:
        level = None
        get_stars = 0
        for t in levels:
            if t[2] == 0 and current_stars >= t[1]:
                # stage 0, get 2 stars
                level = t
                get_stars = 2
                break
        if get_stars == 0:
            for t in levels:
                if t[2] == 1 and current_stars >= t[1]:
                    # stage 1, get 1 star
                    level = t
                    get_stars = 1
                    break
        if get_stars == 0:
            level2max = -1
            for t in levels:
                if t[2] == 0 and current_stars >= t[0]:
                    # stage 0, get 1 star
                    if t[1] > level2max:
                        level = t
                        get_stars = 1
                        level2max = t[1]
            if level:
                level[2] = 1
                level = None
        n_steps += 1
        if level:
            i_del = levels.index(level)
            if i_del in xrange(len(levels)):
                del levels[i_del]
            if len(levels) == 0:
                break
        if get_stars > 0:
            current_stars += get_stars
        else:
            current_stars = 0
            break
#        print levels
    
    if current_stars > 0:
        answer = n_steps
    else:
        answer = "Too Bad"
    
    results.append(format % (i+1, answer))

#print results
outfile = open(os.getcwd() + "/" + filename + postfix_out, "w")
for result in results:
    outfile.write(result)
outfile.close()
