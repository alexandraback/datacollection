def fit(x, r, c):
    if x >= 7:
        return "RICHARD"
    if (r * c)%x != 0:
        return "RICHARD"
    if x > max(r, c):
        return "RICHARD"
    if (x+1)/2 > min(r, c):
        return "RICHARD"
    if x > 3 and x >= 2*min(r, c):
        return "RICHARD"
    return "GABRIEL"

file_read = open("Omino-large.txt")
content = file_read.read()
file_read.close()
file_write = open("output.txt",'w')
lines = content.split("\n")

case = 1
while case <= int(lines[0]):
    info = lines[case].split()
    file_write.write("Case #" +`case`+ ": ")
    file_write.write(fit(int(info[0]),int(info[1]),int(info[2])))
    file_write.write("\n")
    case += 1
file_write.close()