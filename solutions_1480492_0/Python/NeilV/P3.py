INF = 999999999
EPSILON = 0.00000001

class Car(object):
    def __init__(self,info):
        self.v = float(info[1])
        self.pos = float(info[2])
        self.lane = (info[0] == "L")
        
        
    def __lt__(self,other):
        return self.pos < other.pos
        
    def __str__(self):
        return "%.2fm  %im/s" %(self.pos,self.v)
    
    
def done(cars):
    for i in range(1,len(cars)):
        if cars[i].v < cars[i-1].v: return False
    return True


def find_collision(cars):
    ret = INF
    car = None
    
    for i in range(len(cars)):
        for j in range(i+1,len(cars)):
            #if cars[i].pos < cars[j].pos:
            try:
                t = (cars[j].pos-(cars[i].pos+5)) / (cars[i].v - cars[j].v)
                #else:
                    #t = (cars[j].pos+5-cars[i].pos) / (cars[i].v - cars[j].v)
                #print "collision?",cars[j],cars[i],t
                if t > EPSILON and t < ret:
                    ret = t
                    car = i
            except:
                pass
    return ret,car


def update(lanes,t):
    for i in range(2):
        for j in range(len(lanes[i])):
            lanes[i][j].pos += lanes[i][j].v*t
    return lanes


def can_switch(lanes,l,i):
    p = lanes[l][i].pos
    for car in lanes[not l]:
        #print "can switch?",p,car.pos
        #if not (car.pos-p+5 > -EPSILON or p-car.pos+5 > -EPSILON):
        if not (car.pos >= p+5 or p >= car.pos+5):
            return False
    return True
        

data = open("P3.txt")
cases = int(data.readline())
out = open("P3.out","w")

for case in range(cases):
    n = int(data.readline())
    lanes = [[],[]]
    
    for _ in range(n):
        info = data.readline().split()
        lanes[info[0]=="R"].append(Car(info))
        
    lanes[0].sort()
    lanes[1].sort()
        
    total = 0
    poss = True    
    ok1 = done(lanes[0])
    ok2 = done(lanes[1])
    
    while not ok1 or not ok2:
        '''print "left lane:"
        for car in lanes[0]: print car
        print "right lane:"
        for car in lanes[1]: print car    '''
        
        t1 = t2 = INF
        if not ok1:
            t1,car1 = find_collision(lanes[0])
        if not ok2:
            t2,car2 = find_collision(lanes[1])
        if t1 < t2:
            t = t1
            car = car1
            l = 0
        else:
            t = t2
            car = car2
            l = 1
        #print "collision at",t
        total += t
        if car is None:
            break
            
        lanes = update(lanes,t)
        if can_switch(lanes,l,car):
            car = lanes[l].pop(car)
            car.lane = int(not car.lane)
            lanes[not l].append(car)
        else:
            poss = False
            end = total
            break
        
        lanes[0].sort()
        lanes[1].sort()
        ok1 = done(lanes[0])
        ok2 = done(lanes[1])
        print ""
            
        
    '''print "left lane:"
    for car in lanes[0]: print car
    print "right lane:"
    for car in lanes[1]: print car
    print ""
    print poss'''
    
    if poss:
        out.write("Case #%i: Possible\n" %(case+1))
    else:
        out.write("Case #%i: %.9f\n" %(case+1,end))
    print "\n"