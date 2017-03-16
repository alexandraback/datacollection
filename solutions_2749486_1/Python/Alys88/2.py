"""
GCJ 2013
url
"""
import sys
import math

def path(x,y,j):
    """shorter path to 0,0 from X,Y"""
    #x,y = X,Y
    res = []
    while j > 0:
        if x == 0 and y == 0:
            return False
        if x > 0:
            #go west
            res.insert(0,'E')
            x -= j
            j -= 1
        if x < 0:
            #go east
            res.insert(0,'W')
            x += j
            j -= 1
        if y < 0:
            #go north
            res.insert(0,'S')
            y += j
            j -= 1
        if y > 0:
            #go west
            res.insert(0,'N')
            y -= j
            j -= 1
    if (0 != x or 0 != y):
        return False
    return ''.join(res)

def path2(x,y,j):
    """shorter path to 0,0 from X,Y"""
    #x,y = X,Y
    res = []
    while j > 0:
        if x == 0 and y == 0:
            return False
        if y < 0:
            #go north
            res.insert(0,'S')
            y += j
            j -= 1
        if y > 0:
            #go west
            res.insert(0,'N')
            y -= j
            j -= 1
        if x > 0:
            #go west
            res.insert(0,'E')
            x -= j
            j -= 1
        if x < 0:
            #go east
            res.insert(0,'W')
            x += j
            j -= 1
    if (0 != x or 0 != y):
        return False
    return ''.join(res)


def process(f, output):
    nb_of_cases = int(f.readline().rstrip())
    for n in range(1, nb_of_cases + 1):
        print('Case', n)

        #A = f.readline().rstrip()
        X,Y = (int(x) for x in f.readline().rstrip().split())
        #items = [int(x) for x in f.readline().rstrip().split()]
        answer = False
        j = math.floor(math.sqrt(max(abs(X),abs(Y))))
        print(X,Y,j)
        while True:
            answer1 = path(X,Y,j)
            answer2 = path2(X,Y,j)
            if answer1:
                answer = answer1
                break
            if answer2:
                answer = answer2
                break
            j += 1

        print('Answer:', answer)
        output.write('Case #{0}: {1}\n'.format(n, answer))


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("missing argument input_file")
        sys.exit(2)
    input_file = open(sys.argv[1])
    output_file = open(sys.argv[1] + '.out', 'w+')
    process(input_file, output_file)
