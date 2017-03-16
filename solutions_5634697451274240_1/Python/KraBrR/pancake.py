import math

def flip(plist, n):
    l1 = plist[0:n]
    l2 = plist[n:len(plist)]

    l1.reverse()
    for i in range(len(l1)):
        c = l1[i]
        if c == '+':
            l1[i] = '-'
        else:
            l1[i] = '+'
    result = l1 + l2
    '''
    print n
    print plist
    print l1
    print l2
    print result
    print "------------"
    '''
    return result

def get_score(plist):
    score = 0
    for i in range(len(plist)-1, -1, -1):
        if plist[i] != '+':
            break
        else:
            score = score + 1
    return score

def get_a_score(plist):
    score = 0
    for i in range(len(plist)):
        if plist[i] != '-':
            break
        else:
            score = score + 1

    return score

inp = open("B-large.in.txt", 'r')
out = open("large_output.txt", 'w')

ncase = int(inp.readline())

for cidx in range(ncase):
    pstr = inp.readline();
    pstr = pstr.rstrip();
    plist = [c for c in pstr]

    done = False
    counter = 0

    while True:
        # find search range
        srange = 0
        for i in range(len(plist)-1, -1, -1):
            if plist[i] != '+':
                srange = i + 1
                break

        if srange == 0:
            out.write("Case #" + str(cidx+1) + ": " + str(counter) + "\n")
            done = True
            break

        counter = counter + 1

        # find optimum output
        max_score = 0
        a_max_score = 0
        new_plist = list(plist)
        a_new_plist = list(plist)
        for i in range(1, srange+1):
            tmp = flip(list(plist), i)
            score = get_score(tmp)
            a_score = get_a_score(tmp)
            if score == len(plist):
                out.write("Case #" + str(cidx+1) + ": " + str(counter) + "\n")
                done = True
                break
            if score > max_score:
                max_score = score
                new_plist = tmp
            if a_score > a_max_score:
                a_max_score = a_score
                a_new_plist = tmp

        if max_score <= get_score(plist):
            plist = a_new_plist
        else:
            plist = new_plist

        if done:
            break
