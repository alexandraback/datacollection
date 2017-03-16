f = open('D-large.in')
fout = open('D-large.out',mode = 'w')
numtests = int(f.readline())
for x in range(1,numtests+1):
    i = f.readline().split()
    i = [i[0],int(i[1]),int(i[2])]
    if i[0] == '1':
        ans = "GABRIEL"
    elif i[0] == '2':
        ans = ["GABRIEL","RICHARD"][(i[1]*i[2])%2]
    elif i[0] == '3':
        if (i[1] == 1) or (i[2] == 1) or ((i[1]*i[2])%3 != 0):
            ans = "RICHARD"
        else:
            ans = "GABRIEL"
    elif i[0] == '4':
        if (i[1] <= 2) or (i[2] <= 2) or ((i[1]*i[2])%4 != 0):
            ans = "RICHARD"
        else:
            ans = "GABRIEL"
    elif i[0] == '5':
        if (i[1] <= 2) or (i[2] <= 2) or ((i[1]*i[2])%5 != 0) or (i[1]*i[2] == 15):
            ans = "RICHARD"
        else:
            ans = "GABRIEL"
    elif i[0] == '6':
        if (i[1] <= 3) or (i[2] <= 3) or ((i[1]*i[2])%6 != 0):
            ans = "RICHARD"
        else:
            ans = "GABRIEL"
    else: #Chooses second example 7-omino type thing (Hole cant be filled)
        ans = "RICHARD"
    fout.write("Case #"+str(x)+": "+ans+"\n")
f.close()
fout.close()
