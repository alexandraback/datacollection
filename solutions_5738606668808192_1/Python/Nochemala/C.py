#Google Code Jam Qualification Round 2016
#Problem C. Coin Jam
import io

in_file = open('Input.txt',"r")
out_file = open('Output.txt', "w")

in_file.readline()  #first line is 1

NJ = in_file.readline().split(" ")
N = int(NJ[0])
J = int(NJ[1])

out_file.write("Case #1:\n")

for i in range(0,J):
    freeind = int((N/2)-2)
    mid = "{0:0b}".format(i)
    mid = mid.zfill(freeind)
    jamcoinhalf = "1"+mid+"1"
    divstring = ""
    for base in range(2,11):
        div = int(jamcoinhalf, base)
        divstring += " "
        divstring += str(div)

    out_file.write(jamcoinhalf+jamcoinhalf+divstring+"\n")

in_file.close()
out_file.close()