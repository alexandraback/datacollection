'''
Created on Apr 14, 2012

@author: disqiu
'''
import file
import dance

if __name__ == '__main__':
    lines = file.read_file('B-large.in')
    i=0
    write = []
    for line in lines:
        if i != 0:
            #print line
            line_number = line.split(" ")
            #print line_number
            N = int(line_number[0])
            S = int(line_number[1])
            p = int(line_number[2])
            t = line_number[3:]
            #print t
            more=0
            almost=0            

            for tot in t:
                tot_n = int(tot)
                dance_res = dance.vote(tot_n, p)
                print dance_res
                if dance_res[0] == 3:
                    more+=1
                else:
                    if dance_res[1]==-1:
                        if dance_res[0]==2:
                            almost+=1
                        if dance_res[0]==0 and tot_n > 1:
                            almost+=1
            
            if S >= almost:
                more += almost
            else:
                more += S
            
            write.append("Case #"+str(i)+": "+str(more)+"\n")
            
        i+=1
    file.write_file(write,'B-large.out')