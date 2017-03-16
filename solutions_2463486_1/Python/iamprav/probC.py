import os , sys

res = []
def generate(digits):
    
    dict = {}
    dict[1] = [0 , 1 , 2] 
    dict[2] = [11]



    
    for i in range(3 , digits):
        numlist = []

        for j in range(i-2 , -1 , -2):
            #      print j
            diff = (i-j)/2 
            affix = str(10 ** (diff-1))
            if(j != 0):
                for num in dict[j] :
                    snum = affix + str(num)+ affix[::-1]
                    lcount = 0
                    lcount += snum.count('1')
                    if snum.count('2') > 0:
                        lcount += 4
                    
                    if lcount < 10 :
                        numlist.append(int(snum))
            else:
                numlist.append(int(affix + affix[::-1]))
   
        dict[i] = numlist
    


    dict[1].append(3)
    dict[1].remove(0)
    for i in range(2 , digits):
        diff = 2 * (10 ** (i/2-1))
        affix = str(diff)
        if i % 2 == 0 :
            dict[i].append(int(affix + affix[::-1]))
        else :
            dict[i].append(int(affix + "0"+ affix[::-1]))
            dict[i].append(int(affix + "1"+affix[::-1]))


    val = 0
    for i in range(1 , digits):
        res.extend([x**2 for x in dict[i]])
        #print " "
        val += len(dict[i])

#    print val
#    print len(res)

file = open(sys.argv[1],'r')

testnum = int(file.readline())

generate(51)
for test in range(1,testnum+1):

    (x , y) = [int(x) for x in  file.readline().strip().split(' ')]
    ans = len([val for val in res if val >=x and val <=y ])
    print "Case #%d: %d"%(test , ans) 



    


