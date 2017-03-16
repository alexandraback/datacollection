infile = open("A-large.in", "r")
outfile = open("Aout.txt", "w")

total=0
t = int(infile.readline().rstrip())
for z in range(1, t+1):

    #IO here
    raw = infile.readline().split('/')
    top, bottom = int(raw[0]), int(raw[1])
    blah = bottom
    i=0
    while blah%2==0:
        blah = blah/2
        i+=1
    if top%(bottom/(2**i))==0:
        top = top/(bottom/(2**i))
        bottom = bottom/(bottom/(2**i))
        top, bottom = int(top), int(bottom)
        found=False
        generation=1
        while not found:
            total = top*2
            #print(top, bottom, total)
            if top*2//bottom>=1:
                break
            else:
                if top!=1:
                    top = top*2
                else:
                    bottom = bottom//2
                generation+=1
        solution = generation
    else:
        solution="Impossible"
    output = "Case #"+str(z)+": "+str(solution)+"\n"
    print(output)
    outfile.write(output)

infile.close()
outfile.close()
