infile = open('Bsmall.txt', 'r')
outfile = open('Bout.txt', 'w')

raw = infile.readline()
t = int(raw.rstrip())
for z in range(1, t+1):
    raw = infile.readline()
    raw = raw.split()
    raw = [float(i) for i in raw]
    c, f, x = raw[0], raw[1], raw[2]
    production = 2.0
    time = 0
    solved = False
    while not solved:
        timetofarm = c/production
        timetofarm += x/(production+f)
        timetoend = x/production
        #print(timetofarm, timetoend)
        if timetofarm<timetoend:
            time+=c/production
            production+=f
        else:
            time+=timetoend
            solved=True
    outline = "Case #"+str(z)+": "+str(time)+"\n"
    outfile.write(outline)
outfile.close()
        
