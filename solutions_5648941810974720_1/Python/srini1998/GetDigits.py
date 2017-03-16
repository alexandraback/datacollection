def get_digits(str_num):
    #print str_num
    numbers = []
    lst = list(str_num)
    #print lst
    while len(lst)>0:
 
        if 'Z' in lst:
            numbers.append(0)
            lst.remove('Z')
            lst.remove('E')
            lst.remove('R')
            lst.remove('O')
        elif 'W' in lst:
            numbers.append(2)
            lst.remove('T')
            lst.remove('W')
            lst.remove('O')
        elif 'X' in lst:
            numbers.append(6)
            lst.remove('S')
            lst.remove('I')
            lst.remove('X')
        elif 'V' in lst and 'N' in lst and lst.count('E')>1 and 'S'in lst:
            numbers.append(7)
            lst.remove('S')
            lst.remove('E')
            lst.remove('V')
            lst.remove('E')
            lst.remove('N')
        elif 'G' in lst and 'E' in lst and 'I' in lst and 'H' in lst and 'T' in lst:
            numbers.append(8)
            lst.remove('E')
            lst.remove('I')
            lst.remove('G')
            lst.remove('H')
            lst.remove('T')
        elif 'H' in lst and 'T' in lst and 'R' in lst and lst.count('E')>1:
            numbers.append(3)
            lst.remove('T')
            lst.remove('H')
            lst.remove('R')
            lst.remove('E')
            lst.remove('E')
        elif 'U' in lst and 'R' in lst and 'O' in lst and 'F' in lst:
            numbers.append(4)
            lst.remove('F')
            lst.remove('O')
            lst.remove('U')
            lst.remove('R')
        elif 'F' in lst and 'I' in lst and 'V' in lst and 'E' in lst:
            numbers.append(5)
            lst.remove('F')
            lst.remove('I')
            lst.remove('V')
            lst.remove('E')


        elif 'E' in lst and 'I' in lst and lst.count('N')>1:
            numbers.append(9)
            lst.remove('N')
            lst.remove('I')
            lst.remove('N')
            lst.remove('E')

        elif 'O' in lst and 'N' in lst and 'E' in lst:
            numbers.append(1)
            lst.remove('O')
            lst.remove('N')
            lst.remove('E')       

        sortedlst = sorted(numbers)
    return "".join(str(x) for x in sortedlst)           

t = int(raw_input())  # number of cases
for i in xrange(1, t + 1):
    str_num = raw_input()
    print "Case #" + str(i) + ": " + get_digits(str_num)
