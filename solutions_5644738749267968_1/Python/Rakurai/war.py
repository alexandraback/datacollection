import sys
from pprint import pprint

def write(st):
    sys.stdout.write(st)
def writecase(i):
    if i == 0:
        print 'i is 0!!!!!!!!!!!!!!!!!'
    write("Case #%d: " % i)

f = open(sys.argv[1])
T = int(f.readline())

class player(object):
    blocks = []
    score = 0

    def set_blocks(self, line):
        self.blocks = sorted([float(x) for x in line.split()])
        self.blocks.reverse()

class naomi_war(player):
    def play(self):
        block = max(self.blocks)
        return self.blocks.pop(self.blocks.index(block)) # largest
    
    def dplay(self, ken):
        # get rid of blocks that can't win
        if min(ken.blocks) > min(self.blocks):
            # make him burn his biggest block on it
            nblock = self.blocks.pop(self.blocks.index(min(self.blocks)))
            kblock = max(ken.blocks)
            told = kblock - 0.000001
        else:
            # play the smallest block, but tell him he can't beat it
            nblock = self.blocks.pop(self.blocks.index(min(self.blocks)))
            kblock = max(ken.blocks)
            told = kblock + 0.000001
        
#        print told, kblock
        return told, nblock

class ken_war(player):
    def play(self, given):
#        sorted(self.blocks)
        for i in range(len(self.blocks)):
            if self.blocks[i] > given: # first larger
                return self.blocks.pop(i)
        block = min(self.blocks)
        return self.blocks.pop(self.blocks.index(block))

for t in range(1, T+1):
    N = int(f.readline())

    nline = f.readline()
    naomi = naomi_war()
    naomi.set_blocks(nline)

    kline = f.readline()
    ken = ken_war()
    ken.set_blocks(kline)
    
    wscore = 0
    dscore = 0

    #war
    for n in range(N):
        nblock = naomi.play()
#        print 'naomi playing %f' % nblock
        kblock = ken.play(nblock)
#        print 'ken playing %f' % kblock
        
        if kblock < nblock:
            wscore += 1

    naomi.set_blocks(nline)
    ken.set_blocks(kline)
    
    #deceit
    for n in range(N):
        told, nblock = naomi.dplay(ken)
#        print 'naomi telling %f, playing %f' % (told, nblock)
        kblock = ken.play(told)
#        print 'ken playing %f' % kblock
        
        if kblock < nblock:
            dscore += 1
    

    writecase(t)
    write('%d %d\n' % (dscore, wscore))

f.close()