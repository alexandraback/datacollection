from math import factorial

for TC in range(1, int(raw_input()) + 1):
    n = int(raw_input())
    cars = raw_input().split()
    
    # remove redundant letters
    newcars = []
    for car in cars:
        new = [car[0]]
        prev = car[0]
        for char in car[1:]:
            if char != prev:
                new.append(char)
                prev = char
        newcars.append(''.join(new))
    cars = sorted(newcars, key=lambda x:len(x))
    
    # check if orphaned letters are unique and if the same letter appears on the same side twice
    left = [False] * 26
    right = [False] * 26
    freq = [0] * 26
    impossible = False
    for car in cars:
        if len(car) == 1:
            freq[ord(car)-97] += 1
        elif len(car) == 2:
            if left[ord(car[0])-97]:
                impossible = True
            else:
                left[ord(car[0])-97] = True
            freq[ord(car[0])-97] += 1
            if right[ord(car[-1])-97]:
                impossible = True
            else:
                right[ord(car[1])-97] = True
            freq[ord(car[1])-97] += 1
        else:
            if left[ord(car[0])-97]:
                impossible = True
            else:
                left[ord(car[0])-97] = True
            freq[ord(car[0])-97] += 1
            if right[ord(car[-1])-97]:
                impossible = True
            else:
                right[ord(car[-1])-97] = True
            freq[ord(car[-1])-97] += 1
            for char in car[1:-1]:
                if freq[ord(char)-97] > 0:
                    impossible = True
                    break
                else:
                    freq[ord(char)-97] += 1
        if impossible:
            break
    
    if impossible:
        ways = 0
    else:
        ways = 1
        for letter in 'abcdefghijklmnopqrstuvwxyz':
            if freq[ord(car[0])-97] == 0:
                continue
            newcars = []
            left = ""
            right = ""
            singles = 0
            for car in cars:
                if len(car) == 1 and car == letter:
                    singles += 1
                elif len(car) > 1 and car[0] == letter:
                    right = car
                elif len(car) > 1 and car[-1] == letter:
                    left = car
                else:
                    newcars.append(car)
            if singles > 1:
                ways *= factorial(singles)
            if left and right:
                newcars.append(left[0] + right[-1])
            elif left:
                newcars.append(left)
            elif right:
                newcars.append(right)
            elif singles:
                newcars.append(letter)
            cars = newcars
        for car in newcars:
            if len(car) > 1 and car[0] == car[-1]:
                ways = 0
                break
        ways *= factorial(len(newcars))
    
    print "Case #%d: %d" % (TC, ways)
