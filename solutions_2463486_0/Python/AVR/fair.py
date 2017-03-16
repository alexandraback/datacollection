import sys

def palin(n):
    num=str(n)
    L=len(num)
    if all(num[i]==num[L-i-1] for i in range(L//2)):
        return True
    else: return False

def main():
    infile = open(sys.argv[1])
    outfile = open(sys.argv[1][:-2] + 'out', 'w')
    numcases = int(infile.readline())
    maxlen = 26

    words = [[""]]
    for numones in range(4):
        words = words+[[word+'1'+'0'*a for word in words[-1] for a in range(maxlen-len(word))]]
    newlist = [word for elt in words for word in elt][1:]
    newwords1 = [word+word[::-1] for word in newlist]+[word+'1'+word[::-1] for word in newlist]+\
                 [word+'0'+word[::-1] for word in newlist]

    words2 = [[""]]
    for numones in range(2):
        words2 = words2+[[word+'1'+'0'*a for word in words2[-1] for a in range(maxlen-len(word))]]
    newwords2 = [word+'2'+word[::-1] for elt in words2 for word in elt][1:]

    words3 = ['2'+'0'*a for a in range(maxlen)]
    newwords3 = [word+'1'+word[::-1] for word in words3]

    newwords4 = ['2'+'0'*a+'2' for a in range(maxlen*2)]

    thelist = ['1','2','3']+newwords1+newwords2+newwords3+newwords4
    newthelist = [int(word) for word in thelist]

    #newthelist = sorted(newthelist)
    #print(newthelist[:200])

    for case in range(numcases):
        A,B = (int(n) for n in infile.readline().split())
        count = 0
        for num in newthelist:
            count += (A <= num**2)*(num**2 <= B)



        print('Case #%d:' % (case + 1), count, file=outfile)





if __name__ == '__main__':
    main()
