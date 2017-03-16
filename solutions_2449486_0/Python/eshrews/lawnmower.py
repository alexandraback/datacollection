#!/usr/bin/python
import fileinput

def search(law):
    for rown in xrange(len(law)):
        for coln in xrange(len(law[0])):
            h = law[rown][coln]
            v = [x for x in law[rown]]
            a = [x[coln] for x in law]
            validv = True
            for oh in v:
                if h < oh:
                    validv = False
            valida = True
            for oh in a:
                if h < oh:
                    valida = False
            if not valida and not validv:    
                #print rown, coln, v, a
                return False
    return True

case = 0
end = 0
for linenum, line in enumerate(fileinput.input()):
    if linenum == 0:
        cases = int(line)
        end = 0
        continue
    if end == 0:
        size = [int(x) for x in line.split()]
        end += size[0]
        lawn = []
        case += 1
        continue

    lawn.append([int(x) for x in line.split()])

    if end == 1:
        possible = search(lawn)
        res = "NO"
        if possible:
            res = "YES"
        print "Case #{0}: {1}".format(case, res)


    end -= 1
