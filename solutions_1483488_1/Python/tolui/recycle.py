'''
Created on Apr 14, 2012

@author: disqiu
'''
def is_recycled(n,m):
    n_str = str(n)
    lenght =len(n_str)
    for i in range(1,len(n_str)):
        sample = n_str[lenght-i:]+n_str[:lenght-i]
        val = int(sample)
        if(val == m):
            #print (n,m)
            return True
    return False

#print is_recicled(11,21)
#print range(100,200)

def is_recyclable(n, B):
    times = 0
    computed = []
    n_str = str(n)
    lenght =len(n_str)
    for i in range(1,lenght):
        sample = n_str[lenght-i:]+n_str[:lenght-i]
        if sample[0]!='0':
            val = int(sample)
            if(val <= B and val > n and computed.count(val)==0):
                #print (n,m)
                computed.append(val)
                times+=1
    return times

#res = 0
#for i in range(1000000,2000000):
#    res += is_recyclable(i, 2000000)
#print res