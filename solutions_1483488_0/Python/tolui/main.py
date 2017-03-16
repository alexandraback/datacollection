'''
Created on Apr 14, 2012

@author: disqiu
'''
import file
import recycle

if __name__ == '__main__':
    lines = file.read_file('C-small-attempt1.in')
    i=0
    write = []
    
    N = int(lines[0][0])
    for line in lines:
        print (i+0.0)/N
        if i != 0:
            line_number = line.split(" ")
            A = int(line_number[0])
            B = int(line_number[1])

            recycled=0            
        
            for f in range(A,B+1):
                for j in range(f+1,B+1):
                    if recycle.is_recicled(f, j):
                        recycled+=1

            write.append("Case #"+str(i)+": "+str(recycled)+"\n")    
        i+=1
    file.write_file(write,'C-small-attempt1.out')