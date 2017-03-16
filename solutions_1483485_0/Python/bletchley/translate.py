'''
Created on 2012/4/14

@author: bletchley
'''
from string import maketrans

def translate(str):
    ans = str
     
    pass

if __name__ == '__main__':
    map = "yhesocvxduiglbkrhtnwjpfmaq"
    
    file = open("a.in")
    outfile = open("a.out","w")
    num = int(file.readline())
    #print num
    
    for x in range(0,num) :
        line = file.readline()
        str = "Case #%d: " % (x+1)
        #print "abc",
        #print str
        line = line.translate(maketrans("abcdefghijklmnopqrstuvwxyz","yhesocvxduiglbkrztnwjpfmaq"))
        line = line.strip("\n")
        print str+line
        outfile.write(str+line+"\n")
    pass