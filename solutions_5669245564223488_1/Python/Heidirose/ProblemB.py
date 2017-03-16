import math

def trains_with_letter(letter, data):
    to_return = []
    product = 1
    for (train, count) in data:
        if letter in train:
            to_return.append((train,count))
            product *= count
    for item in to_return:
        data.remove(item)
    return to_return, product

def get_last(letter, chunks):
    cands = []
    for chunk in chunks:
        if chunk[0][0] == letter and chunk[0][-1] != letter:
            cands.append(chunk)
    for cand in cands:
        chunks.remove(cand)
    return cands

def get_first(letter, chunks):
    cands = []
    for chunk in chunks:
        if chunk[0][-1] == letter and chunk[0][0] != letter:
            cands.append(chunk)
    for cand in cands:
        chunks.remove(cand)
    return cands

#Ensures the given train is valid
def is_valid_train(train):
    ls = set(["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"])
    previous = None
    for letter in train:
        if previous != None:
            if letter == previous:
                continue
            elif letter in ls:
                previous = letter
                ls.remove(letter)
            else:
                return False
        else:
            previous = letter
            ls.remove(letter)
    return True

    

def read_file():
    file = open("B-large.in")
    out = open("OutputB.txt", 'w')
    T = int(file.readline())
    for t in range(1, T+1):
        print(t)
        alpha = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"] #Need to add the rest
        N = int(file.readline())
        trains = [(x, 1) for x in file.readline().split()]
        valid = True
        for letter in alpha:
            if valid:
                chunks, product = trains_with_letter(letter, trains)
                last_chunks = get_last(letter, chunks)
                first_chunks = get_first(letter, chunks)
                if len(last_chunks) > 1 or len(first_chunks) > 1:
                    valid = False
                    break
                else:
                    other_chunks = chunks
                    num = len(other_chunks)
                    appended = ""
                    if len(first_chunks) == 1:
                        appended += str(first_chunks[0][0])
                    for chunk in other_chunks:
                        appended += chunk[0]
                    if len(last_chunks) == 1:
                        appended += last_chunks[0][0]
                    combos = math.factorial(num) * product
                    if len(appended) > 0:
                        if not is_valid_train(appended):
                            valid = False
                            break
                        trains.append((appended, combos))
        if valid:
            #We have smashed together many trains. What do we have left?
            counts = [int(train[1]) for train in trains]
            product = 1
            for count in counts:
                product *= count
            factorial_left = math.factorial(len(trains))
            #print("result", factorial_left*product)
            out.write("Case #" + str(t) + ": " + str((factorial_left*product)%1000000007) + "\n")
        else:
            #print("bad")
            out.write("Case #" + str(t) + ": 0" + "\n")
        
        #PROBLEM CODE GOES HERE
    out.close()

read_file()
