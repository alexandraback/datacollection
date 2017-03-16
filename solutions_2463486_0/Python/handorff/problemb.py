def is_palindrome(n):
    return n == int(str(n)[::-1])

def main(inpath):
  outfile = open("out.txt", "w")
  lines = open(inpath, "r").read().split('\n')
  cases = int(lines[0])
  palindromes = []
  for i in xrange(1, 3 * 10**7 + 1):
    if is_palindrome(i) and is_palindrome(i**2):
      palindromes.append(i**2)
  
  for i in xrange(1, cases + 1):
    [x, y] = lines[i].split(' ')
    x = int(x)
    y = int(y)

    j = 0
    k = len(palindromes) - 1
    while x > palindromes[j]:
      j += 1
    while y < palindromes[k]:
      k -= 1
    outfile.write("Case #" + str(i) + ": " + str(k - j + 1) + "\n")

main("input.txt")
