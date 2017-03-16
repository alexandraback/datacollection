import sys

alphabet = set("abcdefghijklmnopqrstuvwxyz")
assert len(alphabet) == 26
vowels = set("aeiou")
consonants = alphabet - vowels

def hasNConsonants(s, n):
   for start in range(len(s)):
      substr = s[start:start+n]
      if len(substr) < n:
         continue

      hasEm = all( c in consonants for c in substr )
      if hasEm:
         return True

   return False

def countSubstrings(name, n):
   count = 0
   for start in range(len(name)):
      for end in range(start+1, len(name) + 1):
         substr = name[start:end]
         if hasNConsonants(substr, n):
            count += 1
   return count

def main():
   lines = open(sys.argv[1]).read().split("\n")
   T = int(lines.pop(0))
   for i in range(T):
      name, n = lines.pop(0).split()
      n = int(n)
      status = countSubstrings(name, n)
      print "Case #%s: %s" % ( i+1, status )

if __name__ == "__main__":
   main()
