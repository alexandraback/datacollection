from __future__ import division
import sys


class Ken(object):
    def __init__(self, blocks):
        self.blocks = sorted(blocks)
        self.score = 0
    
    def play_war(self, told):
        played = -1
        for i in xrange(0,len(self.blocks)):
            if self.blocks[i] > told:
                played = self.blocks[i]
                del self.blocks[i]
                break
        if played < 0:
            played = self.blocks[0]
            del self.blocks[0]
        return played


class Naomi(object):
    def __init__(self, blocks):
        self.blocks = sorted(blocks)
        self.score = 0

  
def play_war(naomi,ken):
    for i in xrange(0,len(naomi.blocks)):
        naomi_block = naomi.blocks[i]
        ken_block = ken.play_war(naomi_block)
        if naomi_block > ken_block:
            naomi.score += 1
        else:
            ken.score += 1

  
def num_greater(list1, list2):
    len_list = len(list1)
    list1.sort(reverse=True)
    list2.sort(reverse=True)
    i = 0
    j = 0
    count = 0
    while j < len_list:
        if list1[i] > list2[j]:
            i += 1
            j += 1
            count += 1
        else:
            j += 1
    return count        

    
def main():
    file = open(sys.argv[1], 'r')
    T = int(file.readline().strip())
    
    for trial in xrange(1,T+1):
        sys.stdout.write("Case #%d: " % trial)
        N = int(file.readline().strip())
        
        naomi_blocks = map(float,file.readline().strip().split())
        ken_blocks = map(float,file.readline().strip().split())
        
        sys.stdout.write("%d " % num_greater(naomi_blocks, ken_blocks))
        
        naomi = Naomi(naomi_blocks)
        ken = Ken(ken_blocks)
        play_war(naomi, ken)
        sys.stdout.write("%d\n" % naomi.score)


if __name__ == '__main__':
    main()