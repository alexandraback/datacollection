def doCase(line):
    R = int(line[0])
    C = int(line[1])
    W = int(line[2])
    
    columnsNeeded = max(1, C / W)
    guessesUntilFirstHit = columnsNeeded * R
    
    if (C % W == 0):
        return guessesUntilFirstHit + (W - 1)
    else:
        return guessesUntilFirstHit + W

lines = [line.strip().split() for line in open('A-large.in')]

out = open('output.txt', 'w')
for i in range(1, int(lines[0][0]) + 1):
    out.write("Case #" + str(i) + ": " + str(doCase(lines[i])) + "\n")
out.close