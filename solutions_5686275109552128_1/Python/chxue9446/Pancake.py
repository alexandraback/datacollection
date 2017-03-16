def distribute(lst):
    maximum = max(lst)
    minimum = maximum
    for i in range(maximum)[1:]:
        total = i
        for element in lst:
            total += element/i
            if element%i == 0:
                total -= 1
        if total < minimum:
            minimum = total
    return minimum

file_read = open("Pancake-large.txt")
content = file_read.read()
file_read.close()
file_write = open("output.txt",'w')
lines = content.split("\n")

case = 1
while case <= int(lines[0]):
    lst = lines[2*case].split()
    for i in range(len(lst)):
        lst[i] = int(lst[i])
    file_write.write("Case #" +`case`+ ": ")
    file_write.write(str(distribute(lst)))
    file_write.write("\n")
    case += 1
file_write.close()
