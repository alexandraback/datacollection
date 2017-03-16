def shrink(string):
    el = []
    for i in string:
        if not el or i != el[-1]: el.append(i)
    return ''.join(el)

def main():
    cases = int(raw_input())
    for case in range(1, cases+1):
        word = raw_input().rstrip('+')
        print "Case #%i:" %case, len(shrink(word))

if __name__ == '__main__':
   main()

