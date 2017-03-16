def Game(c, f, t, income, TimeSpent):
    if ( ( (c/income) + (t/(income+f)) ) < (t/income) ): # buy farm
        
        TimeSpent += (c/income)
        income += f
        
        return Game(c, f, t, income, TimeSpent) 
    else:
        return TimeSpent + (t/income)
    

def read_words(afile):
    words = []
    for line in afile:
            words.append(line.strip())
    return words


filename = open('Tim.txt' , 'r')
T = filename.readline() #num test cases
aList = read_words(filename) # array where each element is a line of text

for i in range(int(T)):
    
    stats = aList[i].split()
    c = float(stats[0])
    f = float(stats[1])
    total = float(stats[2])
    income = 2.0
    TimeSpent = 0.0
    time = Game(c, f, total, income, TimeSpent)
    print "Case #"+str(i+1)+": "+str(time)