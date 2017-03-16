'''
Created on 5 may 2012

@author: gnugnu
'''
import GCJ

debug = True

class Run(object):
    def __init__(self, filename_input, filename_output):
        self.file_in = GCJ.InputFile(filename_input)
        self.file_out = GCJ.OutputFile(filename_output)
        a=0
        for line in self.file_in:
            a+=1
            print a
            line = line.split(" ")
            nb = int(line[0])
            notes = [ int(n) for n in line[1:] ]
            s = float(sum(notes))
            moy = s / nb
            s2=False
            n2=0
            for n in notes:
                if n < moy*2:
                    n2+=1
                    s2 += n
                    
            moy2=s/n2
            target = (s2+s)/n2
            out = []
            for n in notes:
                if n < moy*2:
                    out.append("%f" % (( target-n)*100.0/s))
                else:
                    out.append("%f" % (0))
                #out.append("%f" % ((1-n/s)*100))
                #out.append("%f" % ((s -mm -n)/(2*s)))
            self.file_out.prt(" ".join(out))

        self.file_out.close()
        
if __name__ == '__main__':
    #start = Run("mini_A.in", "mini_A.out")
    start = Run("A-small-attempt1.in", "A-small-attempt1.out")