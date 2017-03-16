import struct, fractions

#input read
input_file = open("input1.in", 'rt')
num_cases = int(input_file.readline())

#output write
output_file = open("output1.txt", 'w')

# do the job
def main_job(p,q):
    count = 1
    frac = float(p)/q
    while frac*2 <1:
        frac = frac *2
        count = count +1

    q = q/fractions.gcd(p,q)
    while q%2 ==0:
        q=q/2
    if q ==1:
        return count
    else:
        return -1

for i in range(num_cases):
    print i
    line = input_file.readline()
    line = line.split("/")
    p = int(line[0])
    q = int(line[1])
     
    result = main_job(p,q)

    if result >= 0 :
        output = "Case #%d: %d\n" %(i+1, result)
    else:
        output = "Case #%d: impossible\n" %(i+1)
    
    output_file.write(output)

input_file.close()
output_file.close()