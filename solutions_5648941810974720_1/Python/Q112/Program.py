import sys
import os

In = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[1])
Out = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[2],'w')

if __name__ == '__main__':
    T = int(In.readline())
    for x in range(T):
        print(x)
        nostr = In.readline().rstrip('\n')
        nostr = [a for a in nostr]
        Letters = {'E': 0, 'W': 0, 'U': 0, 'F': 0, 'S': 0, 'V': 0, 'G': 0, 'H': 0, 'N': 0, 'O': 0, 'X': 0, 'Z': 0, 'T': 0, 'I': 0, 'R': 0}
        Numbers = {0: 0, 1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0} 
        for a in nostr:
            Letters[a] += 1
        for a in nostr:
                if a == 'Z':
                    Numbers[0]+=1
                    for b in 'ZERO':
                        Letters[b] -= 1
                if a == 'W':
                    Numbers[2]+=1 
                    for b in 'TWO':
                        Letters[b] -= 1                
                if a == 'U':
                    Numbers[4]+=1
                    for b in 'FOUR':
                        Letters[b] -= 1       
                if a == 'G':
                    Numbers[8]+=1
                    for b in 'EIGHT':
                        Letters[b] -= 1   
                if a == 'X':
                    Numbers[6]+=1
                    for b in 'SIX':
                        Letters[b] -= 1
        nostr = ''
        for a in Letters.keys():
            nostr += Letters[a] * a
            
        for a in nostr:
                if a == 'F':
                    Numbers[5]+=1
                    for b in 'FIVE':
                        Letters[b] -= 1
                if a == 'S':
                    Numbers[7]+=1 
                    for b in 'SEVEN':
                        Letters[b] -= 1                
                if a == 'H':
                    Numbers[3]+=1
                    for b in 'THREE':
                        Letters[b] -= 1       
                if a == 'O':
                    Numbers[1]+=1
                    for b in 'ONE':
                        Letters[b] -= 1
        Numbers[9] = Letters['I']
        
        out = ''
        for a in Numbers.keys():
            out+= Numbers[a]*str(a)               
        Out.write('Case #{}: {}\n'.format(x+1,out))

 
                

                    
                  
            
