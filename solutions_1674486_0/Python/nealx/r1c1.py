'''
Created on 2012-5-6

@author: nealxyc
'''
def solve(adjlist):
    '''
    check if there is any cycle
    '''
    
    for i in range(len(adjlist)):
        curr = i + 1
        parentset = set(adjlist[i])
        nodenum = len(adjlist[i])
        openlist = set(adjlist[i])
        
        while openlist:
            newopen = set()
            if nodenum > len(parentset):
                return 'Yes'
            for node in openlist:
                index = int(node) - 1
                parentset |= set(adjlist[index])
                nodenum += len(adjlist[index])
                newopen |= set(adjlist[index])
            openlist = newopen
        
    return 'No'
    
import sys
if __name__ == '__main__':

    filename = sys.argv[1]
    try:
        with open(filename) as file:
                num = int(file.readline())
                for i in range(1, num +1):
                    count = int(file.readline())
                    adjlist = [] 
                    for k in range(0, count):
                        adjlist.append(set(file.readline().strip().split(' ')[1:]))
                        
                    print "Case #" + str(i) +': '+ str(solve(adjlist))
    except IOError:
        pass