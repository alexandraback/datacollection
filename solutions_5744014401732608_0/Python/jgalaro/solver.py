import math
from collections import Counter


def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

class Importer:
    ''' Reads the file, and queues up inputs'''
    def __init__(self,file):
        self.file = file
        self.fhandle = open(self.file, 'r')
        self.T = int(self.fhandle.readline())

    def pop(self):
        word = [int(x) for x in list(self.fhandle.readline().strip().split(' '))]
        return (word[0],word[1])

class Exporter:
    ''' writes output in proper format, line by line'''
    def __init__(self,file):
        self.file = file
        with open(self.file, 'w'): pass
        self.fhandle = open(self.file, 'w')
        self.ind = 1


    def put(self,impos,ans):
        outs = 'Case #'+str(self.ind)+':'
        if not impos:
            outs += ' IMPOSSIBLE\n'
        else:
            outs += ' POSSIBLE\n'
            B = len(ans)
            for i in range(B):
                for j in range(B):

                    outs += str(ans[i][j])
                outs+='\n'
        self.fhandle.write(outs)
        self.ind += 1



class Runner(object):
    ''' Run algo one case at a time'''

    def run(self, B,M):
        maxPossibility = int(sum([nCr(B-2,i) for i in range(0,B-1)]))
        if M>maxPossibility:
            return((False,0))
        pathMap = list(reversed(list(str("{0:b}".format(M-1)))))
        print(pathMap)
        finMAP = [[0]*(B) for i in range(B)]
        finMAP[0][B-1] = 1
        for i in range(0,B-2):
            if i>=len(pathMap):
                pass
            else:
                if pathMap[i] is '1':
                    finMAP[0][B-2-i] = 1
                    for x in range(B-2-i,B):
                        for j in range(x+1,B):
                            finMAP[x][j] = 1

        return((True,finMAP))












if __name__=='__main__':
    print(Runner)
    read = Importer('B-small-attempt1.in')
    sol = Runner()
    write = Exporter('output.txt')
    for i in range(read.T):
        (B,M) = read.pop()
        #print(B,M)
        (impos,ans) = sol.run(B,M)
        #print(ans)
        write.put(impos,ans)
