from fractions import Fraction

def partelf(frac,gen):
    if frac == Fraction(0,1):
        return 0
    while gen<41:
        gen=gen+1
        frac=frac*Fraction(2,1)
        if  frac >= Fraction(1,1) and frac < Fraction(2,1):
            if partelf(frac-Fraction(1,1),gen) != 'impossible':
                return gen
    return 'impossible'
    
    
def  main(fin,fout):
    inp=fin.readline()
    testcases=int(inp)
    for testcase in range(1,testcases+1):
        numb=fin.readline()
        numb=numb.split('/')
        frac=Fraction(int(numb[0]),int(numb[1]))
        result=partelf(frac,0)
        print result
        fout.write("Case #"+str(testcase)+": "+str(result)+'\n')

if __name__ == '__main__':
    #inputs=[['A-small-attempt0.in','A-small-attempt0.out'],['A-small-attempt1.in','A-small-attempt1.out'],['A-small-attempt2.in','A-small-attempt2.out'],['A-large.in','A-large.in']]
    fin=open('A-large.in','r')
    fout=open('A-large.out','w')  
    main(fin,fout)
    fin.close()
    fout.close()