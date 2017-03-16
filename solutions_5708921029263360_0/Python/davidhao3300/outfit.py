f = open('C-small-attempt1.in')
o = open('output.txt', 'w')
n = int(f.readline())

for i in range(n):
  j, p, s, k = (int(x) for x in f.readline().split(' '))
  print j, p, s, k

  j_p = {}
  j_s = {}
  p_s = {}
  outfits = []
  for x in range(1, j+1):
    for y in range(1, p+1):
      for z in range(1, s+1):
        if j_p.get((x, y), 0) < k:
          if j_s.get((x, z), 0) < k:
            if p_s.get((y, z), 0) < k:
              outfits.append((x, y, z))
              j_p[(x, y)] = j_p.get((x, y), 0) + 1
              j_s[(x, z)] = j_s.get((x, z), 0) + 1
              p_s[(y, z)] = p_s.get((y, z), 0) + 1
  o.write('Case #{}: {}\n'.format(i+1, len(outfits)))
  for outfit in outfits:
    x, y, z = outfit
    o.write('{} {} {}\n'.format(x, y, z))

o.close()
f.close()