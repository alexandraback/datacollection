outfile = "output.txt"

def popinput(input):
    return int(input.readline().split()[0])


def solve(file):
    input = open(file, 'r')
    output = open(outfile, 'w')
    cases = popinput(input)
    for i in range(cases):
        output.write("Case #%(number)d: %(answer)s\n" % {"number":i + 1, "answer":solvecase(input)})

  

def solvecase(input):
    n = popinput(input)
    onestar = {}
    twostar = {}
    for i in range(n):
        line = input.readline().split()
        onestar[i] = int(line[0])
        twostar[i] = int(line[1])
    stars = 0
    plays = 0
    notplayed = set(range(n))
    onestarred = set([])
    while stars < 2 * n:
        for i in notplayed:
            if stars >= twostar[i]:
                notplayed.remove(i)
                stars += 2
                plays += 1
                break
        else:
            for i in onestarred:
                if stars >= twostar[i]:
                    onestarred.remove(i)
                    stars += 1
                    plays += 1
                    break
            else:
                winnable = set(filter(lambda x: stars >= onestar[x], notplayed))
                if not winnable:
                    return "Too Bad"
                best = winnable.pop()
                for i in winnable:
                    if twostar[i] > twostar[best]:
                        best = i
                onestarred.add(best)
                stars += 1
                notplayed.remove(best)
                plays += 1
    return plays
                    
                
        
