f=open('/Users/pruthvikarreddy/Downloads/B-small-attempt0.in').read()
o = open('/Users/pruthvikarreddy/Downloads/out.txt','w')
c=0
v=f.splitlines()
i=1
T=1
class cook():
    def __init__(self,target,farmcost,farmextra):
        self.time=1
        self.balance=2
        self.target=target
        self.farmcost=farmcost
        self.farmextra=farmextra
        self.farms=0
    def run(self):
        while True:
            if self.norm()<self.testbuy():
                return self.norm()
            else:
                self.buy()
    def norm(self):
        return self.time+(self.target-self.balance)/(self.farms*self.farmextra+2)

    def buy(self):

        self.time=self.time+(self.farmcost-self.balance)/(self.farms*self.farmextra+2)
        self.balance=0
        self.farms+=1
        return self.norm()

    def testbuy(self):
        t=self.time+(self.farmcost-self.balance)/(self.farms*self.farmextra+2)
        
        return t+(self.target)/((self.farms+1)*self.farmextra+2)
    
for ix,x in enumerate(f.splitlines()[1:]):
    f,e,t=[float(j) for j in x.split(' ')]
    c=cook(t,f,e)
    o.write('Case #'+str(ix+1)+': '+str(c.run())+'\n')
