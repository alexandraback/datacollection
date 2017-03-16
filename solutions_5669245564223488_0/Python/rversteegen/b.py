import sys

def readints():
    line = sys.stdin.readline().split()
    return [int(x) for x in line]

def readstrs():
    line = sys.stdin.readline().split()
    return line

T, = readints()
for testcase in range(1,T+1):
    N, = readints()
    cars = readstrs()

    groups = []  # list of lists of strs
    groupunions = []  # list of sets of chars

    ways = 1

    # for car in cars:
    #     #if len(car) > 2 and car[0] == 
    #     for gr, gu in zip(groups, groupunions):
    #         if set(car).intersection(gu):
    #             gu.update(car)
    #             gr.append(car)
    #             break
    #     else:
    #         groups.append([car])
    #         groupunions.append(set(car))

    groups = [cars]
    groupunions = [set(''.join(cars))]

    for gr, gu in zip(groups, groupunions):
        cnt = 1
        #print " group", ''.join(gu), 'cars:', gr


        for char in gu:
            right,left,both,none, total = 0,0,0,0,0
            lefty,righty,middle = '','',''
            tlen = 0
            others = []
            for car in gr:
                if char in car:
                    #if car == char * len(car):
                    #    both += 1
                    total += 1
                    tlen += len(car)
                    if car[0] == char and car[-1] == char:
                        both += 1
                        middle += car
                        cnt = (cnt * both) % 1000000007
                    elif car[0] == char:
                        left += 1
                        righty = car
                    elif car[-1] == char:
                        right += 1
                        lefty = car
                    else:
                        none += 1
                        middle = car
                    first, last = car.find(char), car.rfind(char)
                    #print car[first:last+1], first, last
                    if car[first:last+1] != char * (last - first + 1):
                        #print 'bad1', car, char, first, last
                        cnt = 0
                else:
                    others.append(car)
            if right > 1 or left > 1 or none > 1:
                #print 'bad2'
                cnt = 0
            if none > 0 and total > 1:
                #print 'bad3'
                cnt = 0
            newcar = lefty + middle + righty
            if cnt <> 0:
                assert len(newcar) == tlen
            gr = others + [newcar]

        for i in range(2, len(gr) + 1):
            cnt = (cnt * i) % 1000000007

        #print "  becomes", ''.join(gu), 'cars:', gr, cnt
        ways = (ways * cnt) % 1000000007

    #for i in range(2, len(groups) + 1):
    #    ways = (ways * i) % 1000000007

    print "Case #%d: %d" % (testcase, ways)

