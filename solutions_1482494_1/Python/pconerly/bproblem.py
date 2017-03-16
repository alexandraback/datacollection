# problem a, password


def getdata(filename):
    fin = file(filename, 'r')
    t = int(fin.readline())
    games = []

    for i in xrange(t):
        n = int(fin.readline())        
        stages = []
        for j in xrange(n):
            stages.append(Stage(fin.readline().split()))
        stages.reverse()
        games.append(stages)
    #print games
    return games

class Stage:
    def __init__(self, array):
        self.a = int(array[0])
        self.b = int(array[1])
        self.progress = 0
    def __repr__(self):
        return "a:" + str(self.a) + ",b:" + str(self.b)

    def potential(self, stars):
        if self.progress == 0:
            if stars >= self.b:
                return 2
            elif stars >= self.a:
                return 1
        elif self.progress == 1:
            if stars >= self.b:
                return 1
        return 0            

def process(stages):
    prevstars = -1
    stars = 0
    steps = 0
    while len(stages) > 0 and stars != prevstars:
        prevstars = stars
        onepotsPartial = []
        onepotsEmpty = []
        for i in xrange(len(stages)):
            potential = stages[i].potential(stars)
            if potential == 2:
                stars += 2
                steps += 1
                stages.pop(i)
                break
            # store possibility
            elif potential == 1:
                if stages[i].progress == 1:
                    onepotsPartial.append(i)
                elif stages[i].progress == 0:
                    onepotsEmpty.append(i)

        if prevstars == stars:
            if len(onepotsPartial) > 0:
                stars += 1
                steps += 1
                stages.pop(onepotsPartial[0])
            elif len(onepotsEmpty) > 0:
                #print stages
                #print onepotsEmpty
                onepotsEmpty.sort(key=lambda key: stages[key].b, reverse=True)
                #print onepotsEmpty
                stars += 1
                steps += 1
                stages[onepotsEmpty[0]].progress += 1

        # need to use a one-potential.

    if len(stages) > 0:
        return "Too Bad"
    else:
        return steps

def run(filename):
    data = getdata(filename)
    fout = file(filename + ".out", 'w')
    for i in xrange(len(data)):
        answer = "Case #%s: %s" % (i+1, process(data[i]))
        print answer
        fout.write(answer + "\n")
        
if __name__ == "__main__":
    run('B-large.in')
    #run('B-small-attempt0.in')
    #run('B-small-attempt3.in')
    #run('b_sample.txt')




