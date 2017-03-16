import math

#def check(train, char):

def merge(tset, char):
    pure = 0
    misc = 0
    head = ''
    tail = ''
    for t in tset:
        if t.count(char) == len(t):
            pure+=1
        if t[0] != char and t[len(t)-1] == char and head == '':
            head = t
            misc += 1
        if t[0] == char and t[len(t)-1] != char and tail == '':
            tail = t
            misc += 1

    if pure + misc != len(tset):
        return ['a', -1]
    else:
        if head == '':
            head = char
        if tail == '':
            tail = char
        freq = math.factorial(pure)
        return [head+tail, freq]
    
    


def main():
    ifile = open('b.in', 'r')
    ofile = open('b.out', 'w')

    T = int(ifile.readline().strip())
    for case in range(1, T+1):
        N = int(ifile.readline().strip())
        Train = ifile.readline().split()

        alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
        mTrain = []
        possible = True
        for alpha in alphabet:
            tset = []
            for i in reversed(range(0, len(Train))):
                if alpha in Train[i]:
                    tset.append(Train.pop(i))

            multiple = 1
            for i in reversed(range(0, len(mTrain))):
                if alpha in mTrain[i][0]:
                    multiple *= mTrain[i][1]
#                    print('T:', mTrain[i], alpha)
                    tset.append(mTrain[i][0])
                    mTrain.pop(i)
            
            if len(tset) > 1:
                new_train, freq = merge(tset, alpha)
                if freq < 0:
                    possible = False
                    break
                else:
                    mTrain.append([new_train, freq*multiple])
            elif len(tset) == 1:
                mTrain.append([tset[0], 1])

        res = 0
        if possible:
            res = math.factorial(len(mTrain))
            for t in mTrain:
                res *= t[1]
        ofile.write('Case #%d: %d\n' %(case, res))
        print(mTrain)
        print('Case #%d: %d' %(case, res))
        

        
        


#        ofile.write('Case #%d:' %(case))
#        for i in range(N):
#            ofile.write(' %f' %(L[i][2]*100))
#        ofile.write('\n')
            
            
        
                
        
                    
#        print('Case #%d: %.6f' %(case, m))
        
#        ofile.write('Case #%d: %.6f\n' %(case, m))

        

if __name__ == "__main__":
    main()
