'''
Created on Apr 14, 2012

@author: disqiu
'''
import translator
import file


if __name__ == '__main__':
    lines = file.read_file('A-small-attempt0.in')
    i=0
    write = []
    for line in lines:
        if i != 0:
            write.append("Case #"+str(i)+": "+translator.translate(line))
        i+=1
    file.write_file(write,'A-small-attempt0.out')