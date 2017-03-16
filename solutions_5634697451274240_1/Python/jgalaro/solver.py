import math


class Importer:
    ''' Reads the file, and queues up inputs'''
    def __init__(self,file):
        self.file = file
        self.fhandle = open(self.file, 'r')
        self.T = int(self.fhandle.readline())

    def pop(self):
        chain = list(self.fhandle.readline().strip())
        return chain

class Exporter:
    ''' writes output in proper format, line by line'''
    def __init__(self,file):
        self.file = file
        with open(self.file, 'w'): pass
        self.fhandle = open(self.file, 'w')
        self.ind = 1


    def put(self,ans):
        outs = 'Case #'+str(self.ind)+':'
        outs += ' '+str(ans)
        outs+='\n'
        self.fhandle.write(outs)
        self.ind += 1


class Runner(object):
    ''' Run algo one case at a time'''

    def run(self, chain):



        def convert(x):
            if x == '+':
                return 1
            else:
                return 0


        locs = list(map(convert,chain))

        curr = 1
        val = 0
        for x in reversed(locs):
            if x !=curr:
                val += 1
                curr = x

        return val




if __name__=='__main__':
    print(Runner)
    read = Importer('B-large.in')
    sol = Runner()
    write = Exporter('output.txt')
    for i in range(read.T):
        arg = read.pop()
        ans = sol.run(arg)
        write.put(ans)
