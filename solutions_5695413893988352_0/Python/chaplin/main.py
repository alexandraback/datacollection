def problem_2016_1B_B():
    t = int(raw_input())
    for case in range(t):
        c,j=raw_input().split()
        equal=1
        ansc=[]
        ansj=[]
        L=len(c)
        cmp = 0
        for i in range(L):
            if c[i]=='?' and j[i] == '?':
                if cmp == 0:
                    ansc.append('0')
                    ansj.append('0')
                elif cmp == 1:#j is greater
                    ansj.append('0')
                    ansc.append('9')
                else:#c is greater
                    ansj.append('9')
                    ansc.append('0')
            elif c[i] == '?' and not j[i] == '?':
                ansj.append(j[i])
                if cmp == 0:
                    ansc.append(j[i])
                elif cmp==1:#j is greater
                    ansc.append('9')
                else:
                    ansc.append('0')
            elif not c[i]=='?' and j[i]=='?':
                ansc.append(c[i])
                if equal==1:
                    ansj.append(c[i])
                elif cmp==1:#j is greater
                    ansj.append('0')
                else:
                    ansj.append('9')
            else:
                ansj.append(j[i])
                ansc.append(c[i])
                if equal==1:
                    if j[i] > c[i]:
                        cmp=1
                    elif j[i]<c[i]:
                        cmp=-1
                    equal=0
                    
        print 'Case #'+str(case+1)+':', ''.join(ansc), ''.join(ansj)                  
        
def match(word, pattern):
    L=len(word)
    for i in range(L):
        if not pattern[i]=='?' and not pattern[i]==word[i]:
            return False;
    return True;

def problem_2016_1B_B_small():
    t = int(raw_input())
    for case in range(t):
        c,j=raw_input().split()
        mindif=99999
        finalj=0
        finalc=0
        L=len(j)
        max=10**L
        for ansj in range(max):
            wordj=str(ansj).zfill(L)
            if match(wordj,j):
                for ansc in range(max):
                    wordc=str(ansc).zfill(L)
                    if match(wordc, c):
                        if abs(ansj-ansc) < mindif:
                            mindif=abs(ansj-ansc)
                            finalj=wordj
                            finalc=wordc
                        '''
                        elif abs(ansc-ansj) == mindif:
                            if ansc < finalc or (ansc==finalc and ansj < finalj):
                                finalj=ansj
                                finalc-ansc
                        '''
   
        
        print 'Case #'+str(case+1)+':', finalc,finalj 
                
def main():
    problem_2016_1B_B_small()

    
if __name__ == '__main__':
    main()
