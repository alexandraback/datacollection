'''
Created on May 4, 2013

@author: kai
'''
import sys


if __name__ == '__main__':
    hndlin = open(sys.argv[1],'rt')
    hndlout = open(sys.argv[2],'w')
    
    numberCases = int(hndlin.readline())
    
    for index in range(0,numberCases):

        startSize,numberMotes = hndlin.readline().rstrip('\n').split(' ')
        startSize = int(startSize)
        numberMotes = int(numberMotes)
        
        moteListString = hndlin.readline().rstrip('\n').split(' ')
        
        moteList = []
        
        for s in moteListString:
            moteList.append(int(s))
            
        moteList.sort()
        
        moteListCopy = moteList[:]
        
        numberOperations1 = 0
        numberOperations2 = 0
        
        '''
        print "startSize:",startSize
        print "moteList:",moteList
        '''
        
        size1 = startSize
        for number in moteList:
            ''' 
            print "currentSize:",size1
            print "number:",number,"numberOperations:",numberOperations1
            print "moteListCopy",moteListCopy
            '''
            
            
            
            
            
            if size1 <= number:
                if (size1 + size1 -1) > number:
                    size1 = (size1+size1 -1)+number
                    moteListCopy.pop(0)
                    numberOperations1 +=1
                else:
                    numberOperations1 = numberOperations1 + len(moteListCopy)
                    break
            else:
                size1 = size1 + number
                moteListCopy.pop(0)
                
        moteListCopy = moteList[:]
        size2 = startSize
        for number in moteList:
            
            '''
            print "method2"
            
            print "currentSize:",size2
            print "number:",number,"numberOperations:",numberOperations2
            print "moteListCopy",moteListCopy
            '''
            
            
            if size2 <= number:
                if (size2 + size2 -1) > number and size2 != 1:
                    size2 = (size2+size2 -1)+number
                    moteListCopy.pop(0)
                    numberOperations2 +=1
                elif size2 == 1:
                    numberOperations2 = numberOperations2 + len(moteListCopy)
                    break
                else:
                    while size2<=number:
                        size2 = size2 + size2 -1
                        numberOperations2 +=1
                    size2 = size2+number
                    moteListCopy.pop(0)
            else:
                size2 = size2 + number
                moteListCopy.pop(0)
                
        if numberOperations1 > numberOperations2:
            output = "Case #"+str(index+1)+": "+ str(numberOperations2) + '\n'
        else:
            output = "Case #"+str(index+1)+": "+ str(numberOperations1) + '\n'

        print output
        hndlout.write(output)
        
    hndlin.close()
    hndlout.close()