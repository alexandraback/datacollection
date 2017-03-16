'''
Created on 2012-4-13

@author: nealxyc
'''
import string
import sys

input = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jvqz"
output = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give upzq"
table = string.maketrans(input,output)
    
def solve(input):
    return input.translate(table)

if __name__ == '__main__':
    
    
#    print 'ejp mysljylc kd kxveddknmc re jsicpdrysi'.translate(table)
#    print 'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd'.translate(table)
#    print 'de kr kd eoya kw aej tysr re ujdr lkgc jv'.translate(table)

    filename = sys.argv[1]
    try:
        with open(filename) as file:
                num = int(file.readline())
                for i in range(1, num +1):
                    print "Case #" + str(i) +': '+ solve(file.readline().strip())
    except IOError:
        pass