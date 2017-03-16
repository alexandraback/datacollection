with open("B-large.in") as f:
    lines = f.readlines()

def div_ceil(a, b):
    return -(-a // b)

class stack(object):
    def __init__(self, P):
        self.P = P
        self.n = 1

    def __lt__(self, other):
        return self.ratio() > other.ratio()

    def ratio(self):
        return div_ceil(self.P, self.n)

    def __repr__(self):
        return ("(" + str(self.P)+", " + str(self.n) + ", " + str(self.ratio()) + ")")

outputname = 'outputBlarge.txt'
f = open(outputname, 'w')

cases = int(lines[0])
linenum = 1

for i in range(cases):
    D = int(lines[linenum])
    linenum += 1

    dinerline = lines[linenum].split(" ")
    dinerline = [int(j) for j in dinerline]
    linenum += 1

    stacks = [stack(j) for j in dinerline]
    stacks.sort()
    #print(stacks)

    oldminutes = 100000000000
    minutes = stacks[0].ratio()
    numspecials = 0
    while minutes <= oldminutes:
        oldminutes = minutes

        cur_ratio = stacks[0].ratio()
        for j in stacks:
            if j.ratio() == cur_ratio:
                j.n += 1
                numspecials += 1
            else:
                break
        stacks.sort()

        #print(stacks)
        minutes = numspecials + stacks[0].ratio()
        #print(minutes)
        #print(numspecials)

    f.write("Case #" + str(i+1) + ": " + str(oldminutes) + "\n") 

f.close()

with open(outputname, 'r') as f:
    print(f.read())
