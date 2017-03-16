# problem a, password


def getdata(filename):
    fin = file(filename, 'r')
    t = int(fin.readline())
    items = []

    for i in xrange(t):
        item = PassItem(fin.readline().split())
        item.assignprob(fin.readline().split())
        items.append(item)

    return items

class PassItem:
    def __init__(self, array):
        self.a = int(array[0])
        self.b = int(array[1])
        self.prob = []

    def assignprob(self, array):
        for a in array:
            self.prob.append(float(a))
        self.prob.reverse()

    def hitenter(self):
        return float(1 + self.b + 1)
    
    def gettotalprob(self):
        cur = 1.0
        for p in self.prob:
            cur *= p
        self.curprob = cur
        return cur

    def decrementProb(self, i):
        #print "decrement", self.curprob / self.prob[i]
        self.curprob = self.curprob / self.prob[i]

    def getBackspaceProb(self, backnum):
        base = float((self.b - self.a) + (backnum*2) + 1 )
        #print "figuring out base", base, "a", self.a, "self.b", self.b, "backnum", backnum
        return (self.curprob * base) + ((1.0 - self.curprob) * (base + self.b + 1))

def expectedmin(item):
    #print item.a, item.b
    #print item.prob
    
    ans = []
    #init probability
    item.gettotalprob()
    
    #just hit enter
    ans.append(item.hitenter())
    
    # zero backspace
    ans.append(item.getBackspaceProb(0))

    # greater than 1 backspace
    for i in xrange(len(item.prob)):
        item.decrementProb(i)
        ans.append(item.getBackspaceProb(i + 1))
    
    #print "ans", ans
    ans.sort()
    return ans[0]

def run(filename):
    data = getdata(filename)
    fout = file(filename + ".out", 'w')
    for i in xrange(len(data)):
        print "Case #%s: %.6f" % (i+1, expectedmin(data[i]))
        fout.write("Case #%s: %.6f\n" % (i+1, expectedmin(data[i])))
        
if __name__ == "__main__":
    run('A-small-attempt0.in')
    #run('a_sample.txt')




