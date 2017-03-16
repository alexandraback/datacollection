infile = open("Csmall.txt", "r")
outfile = open("Csmallout.txt", "w")

tcase = int(infile.readline().rstrip())
for z in range(1, tcase+1):
    groups = int(infile.readline().rstrip())
    if groups==1:
        data = infile.readline().rstrip().split()
        start, time = int(data[0]), int(data[2])
        slowertime = (360-start)/360*(time+1)
        distfast = (slowertime/time)*360
        if distfast>720-start:
            solution=1
        else:
            solution=0
    else:
        data = infile.readline().rstrip().split()
        h1start, h1time = int(data[0]), int(data[2])
        data = infile.readline().rstrip().split()
        h2start, h2time = int(data[0]), int(data[2])
        time1 = (360-h1start)/360*h1time
        time2 = (360-h2start)/360*h2time
        #print(time1, time2)
        if time1>time2:
            #hiker 1 is slower hiker
            dist2 = (time1/h2time)*360
            if dist2>=720-h2start:
                solution=1
            else:
                solution=0
        else:
            #hiker 2 is slower hiker
            dist1 = (time2/h1time)*360
            if dist1>=720-h1start:
                solution=1
            else:
                solution=0
    outline = "Case #" + str(z) + ": " + str(solution)+"\n"
    outfile.write(outline)
    print(outline)
infile.close()
outfile.close()
