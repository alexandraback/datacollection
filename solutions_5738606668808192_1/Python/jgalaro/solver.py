import math


class Importer:
    ''' Reads the file, and queues up inputs'''
    def __init__(self,file):
        self.file = file
        self.fhandle = open(self.file, 'r')
        self.T = int(self.fhandle.readline())
        params = (self.fhandle.readline().strip().split(' '))
        self.N = int(params[0])
        self.J = int(params[1])


class Exporter:
    ''' writes output in proper format, line by line'''
    def __init__(self,file):
        self.file = file
        with open(self.file, 'w'): pass
        self.fhandle = open(self.file, 'w')
        outs = 'Case #1:\n'
        self.fhandle.write(outs)

    def put(self,val,Dlist):

        outs = val
        for i in Dlist:
            outs += ' '+str(i)
        outs+='\n'
        self.fhandle.write(outs)


class BruteRunner(object):
    ''' Run algo one case at a time'''

    def run(self, N,J):

        outs = []
        proofs = []
        proofs.append([])

        def val2base(val,base):
            num = 0
            places = list(val)
            for i in range(len(places)):
                if places[len(places)-1-i] == '1':
                    num += base**i
            return num
        def base2val(num,base,N):
            places = []
            for i in range(N):
                if num>= base**(N-1-i):
                    places.append('1')
                    num -= base**(N-1-i)
                else:
                    places.append('0')
            return ''.join(places)


        found = 0

        for i in range(2**(N-1)+1,2**(N)-1,2):
            val = base2val(i,2,N)
            Prime = False
            divs = []
            for j in range(2,11):
                test = val2base(val,j)
                div = None
                for k in range(2,17):
                    if test%k == 0:
                        div = k
                        divs.append(div)
                        break


                Prime = Prime or not div
                if Prime:
                    break

            if not Prime:
                print(val)
                outs.append(val)
                print(len(divs))
                proofs[found]=(divs[:])
                found+=1
                if found == J:
                    break
                proofs.append([])



        return outs,proofs






if __name__=='__main__':
    read = Importer('C-large.in')
    sol = BruteRunner()
    write = Exporter('output.txt')
    #arg = read.pop()
    outs,proofs = sol.run(read.N,read.J)
    for i in range(len(outs)):
        write.put(outs[i],proofs[i])
