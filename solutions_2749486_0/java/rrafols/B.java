import java.io.File;
import java.util.LinkedList;
import java.util.Scanner;

public class B {
    public B() {}
    
    private void solve() {
        Scanner sc = new Scanner(System.in);
        
        int numCases = sc.nextInt();
        sc.nextLine();
        
        for(int i = 0; i < numCases; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            
            System.out.println("Case #" + (i + 1) + ": " + solve(x, y));
            sc.nextLine();
        }
    }
    
    private String solve(int x, int y) {
        LinkedList<Node> pendingNodes = new LinkedList<Node>();
        pendingNodes.add(new Node(null, 0, 0, ' ', 0));
        
        boolean found = false;
        while(!found) {
            Node node = pendingNodes.removeFirst();
            
            if(node.x == x && node.y == y) {
                found = true;
                
                StringBuffer sb = new StringBuffer();
                while(node.parent != null) {
                    sb.append(node.m);
                    node = node.parent;
                }
                return sb.reverse().toString();
            } else {
                int step = node.step + 1;
                
                if(y - node.y > step) {
                    pendingNodes.add(new Node(node, node.x, node.y + step, 'N', step));
                } else if(y - node.y < step) {
                    pendingNodes.add(new Node(node, node.x, node.y - step, 'S', step));
                } else {
                    if(node.y <  100) pendingNodes.add(new Node(node, node.x, node.y + step, 'N', step));
                    if(node.y > -100) pendingNodes.add(new Node(node, node.x, node.y - step, 'S', step));
                }
                
                if(x - node.x > step) {
                    pendingNodes.add(new Node(node, node.x + step, node.y, 'E', step));
                } else if(x - node.x < step) {
                    pendingNodes.add(new Node(node, node.x - step, node.y, 'W', step));
                } else {
                    if(node.x <  100) pendingNodes.add(new Node(node, node.x + step, node.y, 'E', step));
                    if(node.x > -100) pendingNodes.add(new Node(node, node.x - step, node.y, 'W', step));
                }
            }
        }
        
        return null;
    }

    public static void main(String[] args) {
        B b = new B();
        b.solve();
    }
    
    class Node {
        Node parent;
        int x;
        int y;
        char m;
        int step;
        
        Node(Node parent, int x, int y, char m, int step) {
            this.x = x;
            this.y = y;
            this.m = m;
            this.parent = parent;
            this.step = step;
        }
    }
}
