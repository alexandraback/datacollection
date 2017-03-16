def sol():
    def rec(order,remaining,trains):
        if len(remaining) == 0:
            mystr = ''
            for i in order:
                mystr+=trains[i]
            chars = []
            for char in mystr:
                if (len(chars)==0):
                    chars.append(char)
                else:
                    if (char == chars[-1]):
                        pass
                    else:
                        chars.append(char)
            for char in chars:
                if chars.count(char)>1:
                    return 0
            return 1
        _order = order[:]
        _remaining = remaining[:]
        total = 0
        for item in _remaining:
            _order.append(item)
            _remaining.remove(item)
            total += rec(_order,_remaining,trains)
        return total
    global line_counter
    trains = inp[line_counter].split(' ')
    line_counter+=1
    remaining = range(len(trains))
    return str(rec([],remaining,trains))
    

with open('B-small-attempt0 (1).in', 'r') as f:
#with open('LOL.txt', 'r') as f:
    inp = f.readlines()
    f.close()
line_counter = 0
T = int(inp[line_counter])
line_counter+=1
data = ''
for i in range(T):
    data += 'Case #%d:' %(i+1) + ' ' + sol()+'\n'
with open('output.txt', 'w') as f:
    f.write(data)
    f.close()
print data
print 'done!'
