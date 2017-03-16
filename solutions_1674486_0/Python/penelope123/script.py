import sys
from copy import deepcopy
from decimal import Decimal

def get_ansestors(histories, found, i):
    ancestors = []
    for p in histories[i-1]['parents']:
        if histories[p-1]['parents'] and not histories[p-1]['ancestors']:
            #print "getting anscestors for ",p
            found = get_ansestors(histories, found, p)
            
        for a in histories[p-1]['ancestors']:
            if a in ancestors:
                found = True
                break
            else:
                ancestors.append(a)
        if p in ancestors:
            found = True
            break
        else:
            ancestors.append(p)
    histories[i-1]['ancestors'] = ancestors
    return found


def main(raw_data):
    data = []
    for line in raw_data:
        data.append(line.strip())
        
    T = data.pop(0)
    for i in range(int(T)):
        strings = data.pop(0).split(' ')
        N = strings.pop(0)
        
        histories = []
        for j in range(int(N)):
            parents = []
            newd = data.pop(0).split(' ')
            M = newd.pop(0)
            for k in range(int(M)):
                parents.append(int(newd.pop(0)))
            
            histories.append({
                'parents':parents,
                'ancestors':[],
            })
        
        reverse_histories = deepcopy(histories)
        reverse_histories.reverse()
        found = False
        for j, history in enumerate(reverse_histories):
            k = len(histories) - j
            #print k
            found = get_ansestors(histories, found, k)
            if found:
                break
            
        #print histories
        #print reverse_histories
        if found:
            print "Case #%s: Yes" % (i+1)
        else:
            print "Case #%s: No" % (i+1)
        
        
if __name__ == "__main__":
    main(sys.stdin)
