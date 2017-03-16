import os
import sys

class P:
    
    def __init__(self, x, y, m=''):
        self.x = x
        self.y = y
        self.m = m
        
    def __eq__(self, other):
        if (self.x, self.y) == (other.x,other.y):
            return True
        return False
    
    def __hash__(self):
        return (self.x, self.y).__hash__()
    
    def adjs(self, l):
        r = set()
        r.add(P(self.x + l, self.y, self.m + 'E'))
        r.add(P(self.x - l, self.y, self.m + 'W'))
        r.add(P(self.x, self.y + l, self.m + 'N'))
        r.add(P(self.x, self.y - l, self.m + 'S'))
        return r
    
    def __str__(self):
        return 'x:' + str(self.x) + ', y:' + str(self.y) + ', m:' + self.m
        

def run(inputFilePath):
    with open(inputFilePath, 'r') as inputFile:
        with open(inputFilePath+'-output.txt', 'w') as outputFile:
            T = int(inputFile.readline())
            print("The input file contains", T, "test cases")
            for t in range (1, T+1):
                print("Processing case #" + str(t))
                input = inputFile.readline().split()
                x = int(input[0])
                y = int(input[1])
                s = P(x, y)
                print('x:', str(x), 'y:', str(y))
                l = 1
                p0 = P(0, 0)
                q = (p0,)
                while True:
                    adj = set()
                    for p in q:
                        adj |= p.adjs(l)
                    if s in adj:
                        adj = list(adj)
                        r = adj[adj.index(s)]
                        output = "Case #" + str(t) + ": " + r.m + "\n"
                        print(output)
                        outputFile.write(output)
                        break
                    
                    l += 1
                    q = adj

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print ("Usage: ", sys.argv[0], "input-file")
        exit(0)
    inputFilePath = sys.argv[1]
    print("Working on input file: [", inputFilePath, "].")
    if not os.path.isfile(inputFilePath):
        print ("Error: the input file is not a valid file")
        exit(1)
    run(inputFilePath)
    print('End.')