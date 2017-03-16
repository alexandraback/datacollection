def isDone(levels):
    for level in levels:
        if level[2] < 2:
            return False
    return True

def checkImpossible(levels):
    for level in levels:
        if level[0] == 0 or level[1] == 0:
            return False
    return True

f = open("B-small-attempt4.in", 'r')
allfile = f.read()
lines = allfile.split("\n")
output = []

process = []
lines.pop(0)
while (len(lines) > 0):
    if lines[0] != "":
        rawr = int(lines.pop(0))
        process.append(lines[0:rawr])
        for i in xrange(rawr):
            lines.pop(0)
    else:
        lines.pop(0)

for game in process:
    levels = [[int(level.split(" ")[0]), int(level.split(" ")[1]), 0] for level in game]
    stars = 0
    done = isDone(levels)
    impossible = checkImpossible(levels)
    num = 0
    while not done and not impossible:
        pickedlevel = False
        for i in xrange(len(levels)):
            test2stars = levels[i]
            if test2stars[2] == 0:
                if test2stars[1] <= stars:
                    stars += 2 - test2stars[2]
                    levels[i][2] = 2
                    pickedlevel = True
                    break
        if not pickedlevel:
            for i in xrange(len(levels)):
                test2star = levels[i]
                if test2star[2] == 1:
                    if test2star[1] <= stars:
                        stars += 2 - test2stars[2]
                        levels[i][2] = 2
                        pickedlevel = True
                        break
        if not pickedlevel:
            for i in xrange(len(levels)):
                test1star = levels[i]
                if test1star[2] == 0:
                    if test1star[0] <= stars:
                        stars += 1 - test1star[2]
                        levels[i][2] = 1
                        pickedlevel = True
                        break
        done = isDone(levels)
        impossible = not pickedlevel
        num += 1
    if impossible and not done:
        output.append("Too Bad")
    else:
        output.append(num)
        
    

f = open("problem2.out", 'w')
for x in xrange(len(output)):
    f.write("Case #" + str(x+1) + ": " + str(output[x]) + "\n")
    print "Case #" + str(x+1) + ": " + str(output[x]) + "\n"
