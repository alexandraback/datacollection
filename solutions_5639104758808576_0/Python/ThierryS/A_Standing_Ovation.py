import sys

def ovation():
    T = int(sys.stdin.readline())
    for case in range(1,T+1):
        
        new_line = sys.stdin.readline()
        spl = new_line.strip().split(' ')
        #assert len(spl) == 2
        Smax, Shyness = int(spl[0]), spl[1]
        #print Smax, len(Shyness)
        #assert Smax+1 == len(Shyness)
        total = 0
        to_invite = 0
        for i in range(1, Smax+2):
            total += int(Shyness[i-1])
            if total < i:
                to_invite += 1
                total += 1
        
        print 'Case #%d: %d' %(case, to_invite)
        
if __name__ == '__main__':
    ovation()
