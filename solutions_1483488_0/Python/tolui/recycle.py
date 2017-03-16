'''
Created on Apr 14, 2012

@author: disqiu
'''
def is_recicled(n,m):
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