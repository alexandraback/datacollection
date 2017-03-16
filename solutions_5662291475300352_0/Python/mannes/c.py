from fractions import Fraction

def mins_to_fin(hiker):
    p, mins = hiker
    return (360-p) * Fraction(mins, 360)

def time_to_catch(h1, h2):
    #divide by 0 error if same speed
    if h1[1] < h2[1]:
        h1, h2 = h2, h1
    #h1 is slower hiker, h1[1] is larger
    rel_speed = 360 * (Fraction(1, h2[1]) - Fraction(1, h1[1]))
    dist = h1[0] - h2[0]
    if dist <= 0:
        dist += 360
    return dist / rel_speed

def ttl(h1, h2):
    #divide by 0 error if same speed
    if h1[1] < h2[1]:
        h1, h2 = h2, h1
    #h1 is slower hiker, h1[1] is larger
    rel_speed = 360 * (Fraction(1, h2[1]) - Fraction(1, h1[1]))
    dist = 360
    return dist / rel_speed
    

def solve(case):
    #only 2-hiker case
    if len(case) == 1:
        return 0
    elif case[0][1] == case[1][1]:
        return 0
    elif case[0][0] == case[1][0]:
        #hikers start at same point
        times = map(mins_to_fin, case)
        ttc = time_to_catch(case[0], case[1])
        print 'samestart'
        if ttc > max(times):
            return 0
        else:
            return 1
    else:
        #hikers start at different places
        ttc = time_to_catch(case[0], case[1])
        if case[1][0] < case[0][0]:
            case.reverse()
            #hiker 0 closer
        t = mins_to_fin(case[0])
        if ttc > t:
            #just follow closer one and you're good
            return 0
        else:
            #if closer one slower, sucks
            if case[0][1] > case[1][1]:
                return 1
            else:
                #closer 1 is faster!
                slower_time = mins_to_fin(case[1])
                fast_loop = time_to_catch(case[0], case[1]) + ttl(case[0], case[1])
                if slower_time < fast_loop:
                    return 0
                else:
                    return 1

f = open('c.in', 'r')
lines = f.readlines()

num_cases = int(lines[0])
lines = lines[1:]
cases = []

for i in xrange(num_cases):
    case = []
    num_lines = int(lines[0])
    for j in xrange(1, num_lines + 1):
        hikers = map(int, lines[j].split())
        for k in xrange(hikers[1]):
            case.append([hikers[0], hikers[2] + k])
    cases.append(case)
    lines = lines[num_lines + 1:]

print cases    

g = open('c.out','w')
for i in xrange(len(cases)):
    g.write('Case #' + str(i + 1) + ': ' + str(solve(cases[i])) + '\n')
g.close()
