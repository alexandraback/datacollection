import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int nCase = cin.nextInt();
        for(int iCase = 1; iCase <= nCase; iCase++) {
            Matrix m = new Matrix(cin);
            while(!m.isEmpty()) {
                boolean mark = false;
                int id = 0;
                for(Iterator<Integer> it = m.rows().iterator();
                    it.hasNext(); id++) {
                    int i = it.next();
                    if(i!=-1 && i==m.min()) {
                        m.removeRow(id);
                        mark = true;
                        break;
                    }
                }
                id = 0;
                for(Iterator<Integer> it = m.columns().iterator();
                    it.hasNext(); id++) {
                    int j = it.next();
                    if(j!=-1 && j==m.min()) {
                        m.removeColumn(id);
                        mark = true;
                        break;
                    }
                }
                if(!mark)
                    break;
            }
            System.out.println("Case #"+iCase+": "+(m.isEmpty() ? "YES" : "NO"));
        }
    }

}

class Matrix {

    private class Node {
        int v;
        Node up, down, left, right;
        public Node(int v) { this.v = v; }
    }
    private int m, n, min;
    private Node h;

    public Matrix(Scanner in) {
        m = in.nextInt();
        n = in.nextInt();
        h = new Node(-1);
        Node node = h;
        for(int i = 0; i<n; i++) {
            node.right = new Node(-1);
            node.right.left = node;
            node = node.right;
            node.up = node;
            node.down = node;
        }
        node.right = h;
        h.left = node;
        node = h;
        for(int i = 0; i<m; i++) {
            node.down = new Node(-1);
            node.down.up = node;
            node = node.down;
            node.left = node;
            node.right = node;
        }
        node.down = h;
        h.up = node;
        min = Integer.MAX_VALUE;
        for(Node i = h.down; i!=h; i = i.down)
            for(Node j = h.right; j!=h; j = j.right) {
                node = new Node(in.nextInt());
                node.up = j.up;
                node.down = j;
                node.left = i.left;
                node.right = i;
                node.up.down = node;
                node.down.up = node;
                node.left.right = node;
                node.right.left = node;
                min = Math.min(min, node.v);
            }
    }

    public int m() { return m; }

    public int n() { return n; }

    public boolean isEmpty() { return m==0; }

    public int min() { return min; }

    public Iterable<Integer> rows() {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        for(Node i = h.down; i!=h; i = i.down) {
            boolean mark = true;
            for(Node j = i.right.right; j!=i; j = j.right)
                if(j.v!=j.left.v) {
                    mark = false;
                    break;
                }
            ans.add(mark ? i.left.v : -1);
        }
        return ans;
    }

    public Iterable<Integer> columns() {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        for(Node j = h.right; j!=h; j = j.right) {
            boolean mark = true;
            for(Node i = j.down.down; i!=j; i = i.down)
                if(i.v!=i.up.v) {
                    mark = false;
                    break;
                }
            ans.add(mark ? j.up.v : -1);
        }
        return ans;
    }

    public void removeRow(int x) {
        Node i = h;
        x++;
        while((x--)!=0)
            i = i.down;
        i.up.down = i.down;
        i.down.up = i.up;
        for(Node j = i.right; j!=i; j = j.right) {
            j.up.down = j.down;
            j.down.up = j.up;
        }
        m--;
        if(m==0) {
            n = 0;
            h.up = h.down = h.left = h.right = h;
        }
        min = Integer.MAX_VALUE;
        for(i = h.down; i!=h; i = i.down)
            for(Node j = i.right; j!=i; j = j.right)
                min = Math.min(min, j.v);
    }

    public void removeColumn(int y) {
        Node i = h;
        y++;
        while((y--)!=0)
            i = i.right;
        i.left.right = i.right;
        i.right.left = i.left;
        for(Node j = i.down; j!=i; j = j.down) {
            j.left.right = j.right;
            j.right.left = j.left;
        }
        n--;
        if(n==0) {
            m = 0;
            h.up = h.down = h.left = h.right = h;
        }
        min = Integer.MAX_VALUE;
        for(i = h.down; i!=h; i = i.down)
            for(Node j = i.right; j!=i; j = j.right)
                min = Math.min(min, j.v);
    }

    public String toString() {
        StringBuilder ans = new StringBuilder();
        for(Node i = h.down; i!=h; i = i.down) {
            for(Node j = i.right; j!=i; j = j.right)
                ans.append(j.v+" ");
            ans.append("\n");
        }
        return new String(ans);
    }

}
