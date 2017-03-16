import math

class Importer:
    ''' Reads the file, and queues up inputs'''
    def __init__(self,file):
        self.file = file
        self.fhandle = open(self.file, 'r')
        self.T = int(self.fhandle.readline())

    def pop(self):
        K,C,S = self.fhandle.readline().split(' ')
        return [int(K),int(C),int(S)]

class Exporter:
    ''' writes output in proper format, line by line'''
    def __init__(self,file):
        self.file = file
        with open(self.file, 'w'): pass
        self.fhandle = open(self.file, 'w')
        self.ind = 1


    def put(self,ans):
        outs = 'Case #'+str(self.ind)+':'
        if ans is None:
            outs += ' IMPOSSIBLE'
        else:
            for i in range(len(ans)):
                outs += ' '+str(ans[i])
        outs+='\n'
        self.fhandle.write(outs)
        self.ind += 1


class Runner(object):
    ''' Run algo one case at a time'''

    def run(self, K,C,S):
        if S<math.ceil(K/C):
            return None

        '''build list of query pos's'''

        outs = []
        if K/C == round(K/C):
            outs = [self.posFinder(n*C,K,C) for n in range(round(K/C))]
        else:
            outs = [self.posFinder(n*C,K,C) for n in range(math.floor(K/C))]
            outs.append(K**C+1-self.posFinder(0,K,min(C,K)))

        if len(outs)>S:
            return None
        else:
            return outs


    def posFinder(self,start,K,C):
        bigSum = 0
        for j in range(C-1):
            bigSum += (start+j)*(K**(C-j-1))
        return start+C+bigSum




if __name__=='__main__':
    print(Runner)
    read = Importer('D-large.in')
    sol = Runner()
    write = Exporter('output.txt')
    for i in range(read.T):
        args = read.pop()
        ans = sol.run(args[0],args[1],args[2])
        write.put(ans)
