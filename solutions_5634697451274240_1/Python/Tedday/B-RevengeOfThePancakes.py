level = "B"
file_is_small = False
attempt = 0
name = level+"-small-attempt"+str(attempt) if file_is_small else level+"-large"
input_file = file(name+".in","r")
output_file = file(name+"-output.txt","w")

def test_case():
    sections = 0
    line = input_file.readline().rstrip()
    c = "random string"
    for char in line:
        if(c != char):
            sections += 1
            c = char
    if(c == '+'):
        sections -=1
    return sections 

T = int(input_file.readline())
for test in xrange(T):
    out = "Case #{0}: {1}".format(test+1,test_case())
    print out
    output_file.write(out + "\n")
input_file.close()
output_file.close()
